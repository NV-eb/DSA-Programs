#include <stdio.h>
int Mean(int n, int arr[]) {
int sum = 0;
for(int i = 0; i < n; i++) {
    sum += arr[i];
}
return sum / n;
}
int Median(int n, int arr[]) {
int sorted[n];
for(int i = 0; i < n; i++) {
    sorted[i] = arr[i];
}
for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
        if(sorted[j] > sorted[j + 1]) {
            int temp = sorted[j];
            sorted[j] = sorted[j + 1];
            sorted[j + 1] = temp;
        }
    }
}
if(n % 2 == 0) {
    return (sorted[n / 2] + sorted[n / 2 - 1]) / 2;
}
else{
    return sorted[n / 2];
}}
int Mode(int n, int arr[]) {
int maxValue = arr[0], maxCount = 0, i, j;
for(i = 0; i < n; i++) {
    int count = 0;
    for(j = 0; j < n; j++) {
        if(arr[j] == arr[i]) {
            count++;
        }
    }
    if(count > maxCount) {
        maxCount = count;
        maxValue = arr[i];
    }
}
return maxValue;
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
    printf("The mean of the array is: %d\n", Mean(n, arr));
    printf("The median of the array is: %d\n", Median(n, arr));
    printf("The mode of the array is: %d\n", Mode(n, arr));
    return 0;

}