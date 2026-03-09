#include<stdio.h>

int main()
{
    char name[5][20];   // space for 5 names (each up to 20 characters)
    int marks[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", name[i]);

        printf("Enter marks of student %d: ", i+1);
        scanf("%d", &marks[i]);
    }

    char (*ptr)[20] = name;  // pointer to name array
    int *ptr1 = marks;

    printf("\nSelected students marks:\n");

    for(int i = 0; i < 5; i++)
    {
        if(i == 3)   // printing only 4th student
        {
            printf("Name: %s  Marks: %d\n", *(ptr+i), *(ptr1+i));
        }
    }
printf("\nAll students marks:\n");
for (int i = 0 ;i<5; i++)
{
    printf("Name: %s  Marks: %d\n", *(ptr+i), *(ptr1+i));
}

    return 0;
}