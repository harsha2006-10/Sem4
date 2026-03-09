#include<stdio.h>
int main(){
    int i,n=5,a[6];
    printf("enter the 5 elements :- ");
    for (i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    if (n==6){
        printf("the array is full, cannot insert more elements\n");
    }
    else{
        printf("the array is not full, you can insert more elements\n");
        int x;
        printf(" enter the element to be inserted :");
        scanf("%d",&x);
        a[n]=x;
        n= n+1;
    }
    printf("the array after insertion is :");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
     return 0;
}