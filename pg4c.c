#include <stdio.h>
void InsertionSort(int arr[], int n) {
    int j=0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            }
            arr[j + 1] = key;
             printf("Step %d:", i);
        for(int k = 0; k < n; k++) {
            printf(" %d", arr[k]);
        }
        printf("\n");
            }
}

int main(){
    int n;
    printf("Enter number of elements in an array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements in the array\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        }
    InsertionSort( arr, n);
    return 0;

}