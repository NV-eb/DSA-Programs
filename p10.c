#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert element
void enqueue(int value) {
    if ((front == -1)) {
        front = rear = 0;
        queue[rear] = value;
        printf("%d enqueued\n", value);
    } else if ((rear + 1) % SIZE != front) {
      rear = (rear + 1) % SIZE;
      queue[rear] = value;
    } else {
        printf("Queue Overflow\n");
   
        
    }
}

// Function to delete element
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("%d dequeued\n", queue[front]);
        if (front == rear) {
            // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Function to display queue
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
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
