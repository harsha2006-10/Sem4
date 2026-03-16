#include<stdio.h>
int main()
{
    int a[8] = {245,260,275,290,300,360,170,185};
    int *ptr = a;
    for(int i=0; i<8; i++){
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
   printf("%p\n", &a[4]);
    return 0;
}