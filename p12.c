#include <stdio.h>

int stck1[100], top1 = -1;
int stck2[100], top2 = -1;

void push1(int item) {
    if (top1 < 99) {
        stck1[++top1] = item;
    } else {
        printf("Stack 1 overflow\n");
    }
}

int pop1() {
    if (top1 >= 0) {
        return stck1[top1--];
    } else {
        printf("Stack 1 underflow\n");
        return -1;
    }
}

void push2(int item) {
    if (top2 < 99) {
        stck2[++top2] = item;
    } else {
        printf("Stack 2 overflow\n");
    }
}

int pop2() {
    if (top2 >= 0) {
        return stck2[top2--];
    } else {
        printf("Stack 2 underflow\n");
        return -1;
    }
}


void Sort() {
    while (top1 >= 0) {
        int temp = pop1();

        
        while (top2 >= 0 && stck2[top2] > temp) {
            push1(pop2());
        }

        
        push2(temp);
    }

}
    

int main() {
    push1(5);
    push1(2);
    push1(8);
    push1(1);
    push1(4);

    printf("Original Stack 1: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stck1[i]);
    }
    printf("\n");

    Sort();

    printf("Sorted Stack 2: ");
    for (int i = 0; i <= top2; i++) {
        printf("%d ", stck2[i]);
    }
    printf("\n");

    return 0;
}
