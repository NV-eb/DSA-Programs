#include <stdio.h>


struct Element {
    int row, col, val;
};

void transpose(int a[][3], int b[][3]) {
    int t = a[0][2];  
    b[0][0] = a[0][1];  
    b[0][1] = a[0][0];  
    b[0][2] = t;
    
    int k = 1;
    for (int i = 0; i < a[0][1]; i++) {  
        for (int j = 1; j <= t; j++) {  
            if (a[j][1] == i) {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
}

int main() {
    int a[100][3], b[100][3];
    int n;
    
    printf("Enter matrix dimensions (rows cols): ");
    scanf("%d %d", &a[0][0], &a[0][1]);
    
    printf("Enter number of non-zero elements: ");
    scanf("%d", &n);
    a[0][2] = n;
    
    printf("Enter elements (row col value):\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    
    transpose(a, b);
    
    printf("\nTransposed matrix:\n");
    printf("Row Col Value\n");
    for (int i = 0; i <= n; i++) {
        printf("%d   %d   %d\n", b[i][0], b[i][1], b[i][2]);
    }
    
    return 0;
}
