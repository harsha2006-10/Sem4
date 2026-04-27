#include <stdio.h>

int main() {
    int s[10] = {2,4,5,1}, top = 4, max = 10;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top == max) {
                    printf("Stack Overflow\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    s[top] = value;
                    top++;
                }
                break;

            case 2: 
                if (top == 0) {
                    printf("Stack Underflow\n");
                } else {
                    top--;
                    printf("Popped value: %d\n", s[top]);
                }
                break;

            case 3: 
                printf("Stack: ");
                for (int i = 0; i < top; i++) {
                    printf("%d ", s[i]);
                }
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}