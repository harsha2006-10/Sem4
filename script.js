// Simple BST and AVL implementation with SVG rendering
class Node{
  constructor(val){this.val=val;this.left=null;this.right=null;this.height=1}
}

class BST{
  constructor(){this.root=null}
  insert(val){this.root=this._insert(this.root,val)}
  _insert(node,val){
    if(!node) return new Node(val);
    if(val===node.val) return node; // ignore duplicates
    if(val<node.val) node.left=this._insert(node.left,val);
    else node.right=this._insert(node.right,val);
    return node;
  }
  find(val){let cur=this.root;while(cur){if(val===cur.val)return cur;cur=val<cur.val?cur.left:cur.right}return null}
  delete(val){this.root=this._delete(this.root,val)}
  _delete(node,val){
    if(!node) return null;
    if(val<node.val) node.left=this._delete(node.left,val);
    else if(val>node.val) node.right=this._delete(node.right,val);
    else{
      if(!node.left) return node.right;
      if(!node.right) return node.left;
      let succ=this._min(node.right);
      node.val=succ.val;
      node.right=this._delete(node.right,succ.val);
    }
    return node;
  }
  _min(node){while(node.left)node=node.left;return node}
}

class AVL extends BST{
  _height(n){return n? n.height:0}
  _update(n){n.height=1+Math.max(this._height(n.left),this._height(n.right))}
  _balance(n){return n? this._height(n.left)-this._height(n.right):0}
  _rightRotate(y){let x=y.left;let T2=x.right;x.right=y;y.left=T2;this._update(y);this._update(x);return x}
  _leftRotate(x){let y=x.right;let T2=y.left;y.left=x;x.right=T2;this._update(x);this._update(y);return y}
  _insert(node,val){
    if(!node) return new Node(val);
    if(val===node.val) return node;
    if(val<node.val) node.left=this._insert(node.left,val);
    else node.right=this._insert(node.right,val);
    this._update(node);
    let balance=this._balance(node);
    // LL
    if(balance>1 && val<node.left.val) return this._rightRotate(node);
    // RR
    if(balance<-1 && val>node.right.val) return this._leftRotate(node);
    // LR
    if(balance>1 && val>node.left.val){node.left=this._leftRotate(node.left);return this._rightRotate(node)}
    // RL
    if(balance<-1 && val<node.right.val){node.right=this._rightRotate(node.right);return this._leftRotate(node)}
    return node;
  }
  _delete(node,val){
    if(!node) return null;
    if(val<node.val) node.left=this._delete(node.left,val);
    else if(val>node.val) node.right=this._delete(node.right,val);
    else{
      if(!node.left) return node.right;
      if(!node.right) return node.left;
      let succ=this._min(node.right);
      node.val=succ.val;
      node.right=this._delete(node.right,succ.val);
    }
    this._update(node);
    let balance=this._balance(node);
    if(balance>1 && this._balance(node.left)>=0) return this._rightRotate(node);
    if(balance>1 && this._balance(node.left)<0){node.left=this._leftRotate(node.left);return this._rightRotate(node)}
    if(balance<-1 && this._balance(node.right)<=0) return this._leftRotate(node);
    if(balance<-1 && this._balance(node.right)>0){node.right=this._rightRotate(node.right);return this._leftRotate(node)}
    return node;
  }
}

// Rendering and UI
const svg=document.getElementById('svg');
const modeSel=document.getElementById('mode');
const valInput=document.getElementById('value');
const insertBtn=document.getElementById('insert');
const removeBtn=document.getElementById('remove');
const searchBtn=document.getElementById('search');
const clearBtn=document.getElementById('clear');
const logInner=document.getElementById('logInner');

let bst=new BST();
let avl=new AVL();

function log(msg){const p=document.createElement('div');p.textContent=msg;logInner.prepend(p)}

function current(){return modeSel.value==='avl'?avl:bst}

function clear(){bst=new BST();avl=new AVL();render()}
clearBtn.addEventListener('click',()=>{clear();log('Cleared trees')})

insertBtn.addEventListener('click',()=>{
  const v=Number(valInput.value);
  if(Number.isNaN(v)) return log('Enter a number');
  current().insert(v);
  log(`Inserted ${v} into ${modeSel.value.toUpperCase()}`);
  render();
})

removeBtn.addEventListener('click',()=>{
  const v=Number(valInput.value);
  if(Number.isNaN(v)) return log('Enter a number');
  current().delete(v);
  log(`Deleted ${v} from ${modeSel.value.toUpperCase()}`);
  render();
})

searchBtn.addEventListener('click',()=>{
  const v=Number(valInput.value);
  if(Number.isNaN(v)) return log('Enter a number');
  const found=current().find(v);
  log(found?`Found ${v}`:`${v} not found`);
  render(found?found.val:null);
})

function render(highlightVal=null){
  while(svg.firstChild) svg.removeChild(svg.firstChild);
  const tree=current().root;
  if(!tree) return;
  // compute positions
  let positions=new Map();
  let x=0;
  function inorder(n,depth){
    if(!n) return;
    inorder(n.left,depth+1);
    positions.set(n, {x: x++ * 70 + 40, y: depth*90 + 40, depth});
    inorder(n.right,depth+1);
  }
  inorder(tree,0);
  // draw edges
  for(let [n,pos] of positions){
    if(n.left){let p=positions.get(n.left);drawLine(pos.x,pos.y,p.x,p.y)}
    if(n.right){let p=positions.get(n.right);drawLine(pos.x,pos.y,p.x,p.y)}
  }
  // draw nodes
  for(let [n,pos] of positions){
    drawNode(pos.x,pos.y,n.val, n.val===highlightVal);
  }
}

function drawLine(x1,y1,x2,y2){
  const ln=document.createElementNS('http://www.w3.org/2000/svg','line');
  ln.setAttribute('x1',x1);ln.setAttribute('y1',y1);ln.setAttribute('x2',x2);ln.setAttribute('y2',y2);
  ln.setAttribute('class','edge');svg.appendChild(ln);
}

function drawNode(x,y,val,highlight=false){
  const g=document.createElementNS('http://www.w3.org/2000/svg','g');
  const c=document.createElementNS('http://www.w3.org/2000/svg','circle');
  c.setAttribute('cx',x);c.setAttribute('cy',y);c.setAttribute('r',18);
  c.setAttribute('class', highlight? 'highlight' : 'node');
  const t=document.createElementNS('http://www.w3.org/2000/svg','text');
  t.setAttribute('x',x);t.setAttribute('y',y+4);t.setAttribute('class','node-text');
  t.textContent=val;
  g.appendChild(c);g.appendChild(t);svg.appendChild(g);
}

// initial demo
[50,30,70,20,40,60,80].forEach(v=>{bst.insert(v);avl.insert(v)});
render();
