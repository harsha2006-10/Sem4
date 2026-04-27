#include<stdio.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;

int main() {
    int choice, value;

    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);;

        switch(choice) {

            case 1: 
                if((rear + 1) % MAX == front) {
                    printf("Queue is full\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);

                    if(front == -1) {
                        front = 0;
                        rear = 0;
                    } else {
                        rear = (rear + 1) % MAX;
                    }

                    queue[rear] = value;
                }
                break;

            case 2: 
                if(front == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Dequeued value: %d\n", queue[front]);

                    if(front == rear) {
                        front = rear = -1;
                    } else {
                        front = (front + 1) % MAX;
                    }
                }
                break;

            case 3: 
                if(front == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue: ");
                    int i = front;

                    while(1) {
                        printf("%d ", queue[i]);
                        if(i == rear) break;
                        i = (i + 1) % MAX;
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