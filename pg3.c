#include<stdio.h>
int main(){
    int S1[4]={1, 2, 3, 4};
    int S2[3]={3, 4, 5};
    printf("S1={1, 2, 3, 4}\n");
    printf("S2={3, 4, 5}\n");
    printf("Intersection of S1 and S2 is:\n ");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(S1[i] == S2[j]){
                printf("%d ", S1[i]);
            }
        }
    }
}