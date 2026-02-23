#include<stdio.h>
int main()
{
    int collction = 31500;
    int *ptr = &collction;
    printf("value of the collection: %d\n", collction);
    printf("address of the collection: %p\n", (int *)&collction);
    return 0;
}