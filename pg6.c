#include "stdio.h"
#include "string.h"
char str[100];
int top=-1;
void push(char stck[],int l, char item)
{      
       if (top==l-1)
    {
        
        printf("Stack overflow");
    }
    stck[++top]=item;
    
   }
void pop(char stck[])
{
   
   if (top<0)
   {
    printf("Stack underflow");
   }
   
    printf("%c",stck[top]);
    top--;
   }



int main() {
    int l;
    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);
    l=strlen(str);
   
    char stck[l];
    for(int i=0;i<l;i++)
    {
       push(stck,l,str[i]);
    }
     printf("Reversed string is:\n");
   for (int i=0;i<l;i++)
   {
    pop(stck);
   }
    return 0;
}