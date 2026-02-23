#include<stdio.h>
int main()
{
    float no = 3.14;
    float *p =&no;
    printf("Value of no: %f\n", no);
    printf("Address of no: %p\n", (float *)&no);
    printf("value of p :%p\n",(float *)p);
    return 0;
}