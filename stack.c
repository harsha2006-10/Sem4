#include<stdio.h>
int main()
{
    int s[8]={2,4,5,1},top=4,max=8;
    int *ptr = s;

    while (top < max)
    {
        printf("enter the value to be pushed: ");
        scanf("%d",&s[top]);
        top = top +1;
    }

    printf("stack after push: ");
    for(int i=0; i<top; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    while (top > 0)
    {
       if (top == 0) {
                    printf("Stack Underflow\n");
                } else {
                    top--;
                    printf("Popped value: %d\n", s[top]);
                }
                break;
    }
    printf("stach after pop: ");
    for(int i=0; i<top; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    return 0;
}