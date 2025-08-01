#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int Que[MAX], f = -1, r = -1;

// Enqueue operation
void EnQ(int val) {
    if (r == MAX - 1)
        return;
    if (f == -1)
        f = 0;
    Que[++r] = val;
}

// Dequeue operation
int DeQ() {
    if (f == -1 || f > r) {
        printf("Empty Queue\n");
        return -1;
    }
    return Que[f++];
}

// Display queue elements
void display() {
    if (f == -1 || f > r) {
        printf("Empty Queue\n");
    } else {
        printf("Queue Elements: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", Que[i]);
        }
        printf("\n");
    }
}

// Reverse queue using recursion
void revQ() {
    if (f == -1 || f > r)
        return;

    int temp = DeQ();
    revQ();
    EnQ(temp);
}

// Main function to test
int main() {
    EnQ(10);
    EnQ(20);
    EnQ(30);
    EnQ(40);
    EnQ(50);

    printf("Original Queue:\n");
    display();

    revQ();

    printf("Reversed Queue:\n");
    display();

    return 0;
}
