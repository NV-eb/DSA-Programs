#include<stdio.h>

void LinearSearch(int arr[], int n, int x)
{int c=0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]==x)
        {
            c=1;
            break;
        }
    }
    if(c==1)
    {
        printf("%d is present in array",x);
    }
    else{
        printf("%d is not present in array",x);
    }
}
int main(){
    int n,x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elememts in an array\n",n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);

}
printf("Enter a search value:\n");
scanf("%d",&x);
LinearSearch( arr,  n,  x);
return 0;
}
