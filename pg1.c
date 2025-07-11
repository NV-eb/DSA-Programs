#include <stdio.h>
void rotate(int n, int arr[],char dir, int k){
int temp[n],j=0;
if(dir == 'L' || dir == 'l'){
    for(int i = 0; i < n; i++){
        j=i+k;
        if(j>=n){
            j=j-n;
        }
        temp[j]=arr[i];
    }
}
else if(dir == 'R' || dir == 'r'){
    for(int i = 0; i < n; i++){
        j=i-k;
        if(j<0){
            j=j+n;
        }
        temp[j]=arr[i];
    }
}
for(int i = 0; i < n; i++){
    arr[i] = temp[i];
}
printf("The rotated array is:\n");
for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
}
}
int main(){
int n;
printf("Enter the number of elements in the array:\n ");
scanf("%d", &n);
int arr[n];
printf("Enter %d elements of the array:\n ", n);
for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
}
char dir;
printf("Enter the direction of rotation (L for left, R for right):\n ");
scanf(" %c", &dir);
int k;
printf("Enter the number of rotations:\n ");
scanf("%d", &k);
rotate(n, arr, dir, k);
return 0;
}