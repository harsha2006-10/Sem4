#include<stdio.h>
int main()
{
    char *name[5] = {"ram", "sham", "syam", "david", "john"};
    int marks[5] = {90, 80, 70, 60, 50};
    char **ptr = name;
    int *ptr1 = marks;
    printf("Selected students marks:\n");
    for(int i = 0; i < 5; i++)
    {
        if(i == 3)   
        {
            printf("Name: %s  Marks: %d\n", *(ptr+i), *(ptr1+i));
        }
    }
    return 0;
}