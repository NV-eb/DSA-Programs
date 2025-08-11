#include <stdio.h>
#define max_terms 100
int n1,n2;
struct terms {
    int coeff;
    int exp;
} polynomialA[max_terms], polynomialB[max_terms], polynomialResult[max_terms];

void PolyA()
{
    int  i;
    printf("Enter the number of terms in polynomial A: ");
    scanf("%d", &n1);
    printf("Enter the coefficients and exponents for polynomial A:\n");
    for (i = 0; i < n1; i++) {
        printf("Term : ");
        scanf("%d %d", &polynomialA[i].coeff, &polynomialA[i].exp);
    }
    for(int i=0;i<n1;i++) {
        printf("%dx^%d\t",  polynomialA[i].coeff, polynomialA[i].exp);
    }
    printf("\n");
}

void PolyB()
{
    int  i;
    printf("Enter the number of terms in polynomial B: ");
    scanf("%d", &n2);
    printf("Enter the coefficients and exponents for polynomial B:\n");
    for (i = 0; i < n2; i++) {
        printf("Term: ");
        scanf("%d %d", &polynomialB[i].coeff, &polynomialB[i].exp);
    }
    for(int i=0;i<n2;i++) {
        printf("%dx^%d\t",  polynomialB[i].coeff, polynomialB[i].exp);
    }
    printf("\n");
}

void PolyAdd()
{
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        if (polynomialA[i].exp > polynomialB[j].exp) {
            polynomialResult[k].coeff = polynomialA[i].coeff;
            polynomialResult[k].exp = polynomialA[i].exp;
            i++;
        } else if (polynomialA[i].exp < polynomialB[j].exp) {
            polynomialResult[k].coeff = polynomialB[j].coeff;
            polynomialResult[k].exp = polynomialB[j].exp;
            j++;
        } else {
            polynomialResult[k].coeff = polynomialA[i].coeff + polynomialB[j].coeff;
            polynomialResult[k].exp = polynomialA[i].exp;
            i++;
            j++;
        }
        k++;
    }
    
    // Handle remaining terms from polynomial A
    while (i < n1) {
        polynomialResult[k].coeff = polynomialA[i].coeff;
        polynomialResult[k].exp = polynomialA[i].exp;
        i++;
        k++;
    }
    
    // Handle remaining terms from polynomial B
    while (j < n2) {
        polynomialResult[k].coeff = polynomialB[j].coeff;
        polynomialResult[k].exp = polynomialB[j].exp;
        j++;
        k++;
    }
    
    // Update the result count
    n1 = k;
}

void PolyPrint()
{
    int i;
    printf("Resultant Polynomial: ");
    for (i = 0; i < n1; i++) {
        if (polynomialResult[i].coeff != 0) {
            printf("%dx^%d\t ", polynomialResult[i].coeff, polynomialResult[i].exp);
        }
    }
    printf("\n");
}

int main() {
    printf("Note: Enter terms in descending order of exponents\n");
    PolyA();
    PolyB();
    PolyAdd();
    PolyPrint();
    return 0;
}
