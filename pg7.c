#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;
int sorted[SIZE], top2 = -1;

// Push to main stack
void push(int val) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

// Pop from main stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Push to sorted stack
void push2(int val) {
    if (top2 == SIZE - 1) {
        printf("Sorted Stack Overflow\n");
        return;
    }
    sorted[++top2] = val;
}

// Pop from sorted stack
int pop2() {
    if (top2 == -1) {
        printf("Sorted Stack Underflow\n");
        return -1;
    }
    return sorted[top2--];
}

// Sort the stack using another stack
void sortStack() {
    while (top != -1) {
        int temp = pop();

        // While sorted stack is not empty and top is greater than temp
        while (top2 != -1 && sorted[top2] > temp) {
            push(pop2()); // move back to original stack
        }

        push2(temp); // place temp in correct position in sorted stack
    }

    // Move sorted elements back to original stack
    while (top2 != -1) {
        push(pop2());
    }
}

// Display the stack
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack (Top to Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, val;

    printf("Enter number of elements to push into stack: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("Original Stack:\n");
    display();

    sortStack();

    printf("Sorted Stack:\n");
    display();

    return 0;
}

