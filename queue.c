#include<stdio.h>
#define MAX 10

int queue[MAX], front =-1, rear =-1;

int main(){
    int choice, value;

    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(rear == MAX-1){
                    printf("Queue is full\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    rear++;
                    queue[rear] = value;
                    if(front == -1) {
                        front = 0;
                    }
                }
                break;

            case 2:
                if(front == -1 || front > rear){
                    printf("Queue is empty\n");
                } else {
                    printf("Dequeued value: %d\n", queue[front]);
                    front++;
                }
                break;

            case 3:
                if(front == -1 || front > rear){
                    printf("Queue is empty\n");
                } else {
                    printf("Queue: ");
                    for(int i = front; i <= rear; i++){
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
