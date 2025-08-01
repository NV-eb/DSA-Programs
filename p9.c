#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert element
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1 && rear == -1) 
        {
        front = 0;
        queue[++rear] = value;
        } else {
            queue[++rear] = value;
        }
        printf("%d enqueued\n", value);
    }
}

// Function to delete element
void dequeue() {
    if (front == -1 ) {
        printf("Queue Underflow\n");
    } else {
        printf("%d dequeued\n", queue[front]);
        front++;
    }
}

// Function to display the queue
void display() {
    if (front == -1 ) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
