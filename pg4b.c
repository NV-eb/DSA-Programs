#include <stdio.h>
void SelectionSort(int n, int arr[]) {
    int temp, minIndex;
    printf("The array in descending order using selection sort is:\n");
    for(int i = 0; i < n - 1; i++) {
        minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[minIndex]) {
                minIndex = j;
            }
        } 
        printf("Step %d:", i + 1);
        for(int k = 0; k < n; k++) {
            printf(" %d", arr[k]);
        }
        printf("\n");
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
       
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
    SelectionSort(n, arr);
    return 0;
}