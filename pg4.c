#include <stdio.h>
void BubbleSort(int n, int arr[]) {
     int temp;
    printf("The array in descending order using bubble sort is:\n");
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printf("Step %d:", i + 1);
            for(int k = 0; k < n; k++) {
                printf(" %d", arr[k]);
            }
            printf("\n");
        }
    }
    printf("The final sorted array is:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
       
}
int main() {
    int n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of the array:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
   BubbleSort(n, arr);
    
    return 0;
}
