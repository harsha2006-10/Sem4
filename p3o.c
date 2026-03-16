#include<stdio.h>
int main()
{
    int a[7] = {100,150,170,180,190,200,250};
    int *ptr = a;
    for(int i=0; i<7; i++){
        printf("the value of a[%d] is : %d\n", i, a[i]);
        printf("&a[%d] is : %p\n", i, (void*)&a[i]);
        printf("%d\n",*(ptr+i));
    }
    printf("%zu\n", sizeof(a));
    * a = 52;
    printf("the value of a[1] is : %d\n", a[1]);
     printf("%p\n", &a[0]);
   int my_int = 10;
   printf(" %zu \n", sizeof(my_int));
   printf("%p\n", &a[2]);
   int mynum[4]={25,50,75,100};
   int *ptr1 = mynum;
   for(int i=0; i<4; i++){
    printf("%d\n",*(ptr1+i));
        
   }    
   printf("%p\n", &mynum);
    return 0;
}