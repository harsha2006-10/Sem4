#include<stdio.h>
int main()
{
    char name[10] ="harsha";
    char *ptr=name;
    printf("ptr value (points to): %p\n", (void *)ptr);
    printf("address of ptr variable: %p\n", (void *)&ptr);
    printf("address of name array: %p\n", (void *)name);
    return 0;
}