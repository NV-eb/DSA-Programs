#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*header;

void createlist(int n)
{
    struct node *newnode, *temp;
    int data, i;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory");
    }
    else{
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        header = newnode;
        temp = newnode;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            if(newnode == NULL)
            {
                printf("Unable to allocate memory");
                break;
            }
            else{
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newnode->data = data;
                newnode->next = NULL;
                temp->next = newnode;
                temp = newnode;
            }
        }
    }
}

void displayList()
{
    struct node *temp;
    
    if(header == NULL)
    {
        printf("List is empty.");
        return;
    }
    temp = header;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertAtBeginning()
{
    struct node *newnode;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    else{
        printf("Enter the data for the new node: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = header;
        header = newnode;
    }
}
void insertAtEnd()
{
    struct node *newnode, *temp;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    else{
        printf("Enter the data for the new last node: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        
        if(header == NULL)
        {
            header = newnode;
        }
        else
        {
            temp = header;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}
void insertAtMiddle()
{
    struct node *newnode, *temp, *prev;
    int data,pos,i;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    else{
        printf("Enter the position to insert the new node: ");
        scanf("%d", &pos);
        printf("Enter the data for the new node: ");
        scanf("%d", &data);
        newnode->data = data;
        
        if(pos == 1) // Insert at the beginning
        {
            newnode->next = header;
            header = newnode;
            return;
        }
        
        temp = header;
        for(i = 0; i < pos-1  && temp != NULL; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        
        if(temp == NULL) // Insert at the end
        {
            prev->next = newnode;
            newnode->next = NULL;
        }
        else // Insert in the middle
        {
         prev->next = newnode;
            newnode->next = temp;
        }
    }
    
}
void deleteAtStart()
{
    struct node *temp;
    if(header == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    temp=header;
    header=header->next;
    free(temp);
    printf("Node deleted from the start.\n");
}

void deleteAtEnd()
{
    struct node *temp, *prev;
    if(header == NULL)
    {
        printf("List is empty, nothing to delete");
        return;
    }
    
    // If there's only one node
    if(header->next == NULL)
    {
        free(header);
        header = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    
    temp = header;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Node deleted from the end.\n");
}
void deleteAtBtw()
{
    struct node *temp, *prev;
    int pos,i;
    if(header == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);
    if(pos == 1) // Delete from the beginning
    {
        temp=header;header=header->next;
        free(temp);
        printf("Node deleted from the start.\n");
        return;
    }
    temp=header;
    for(i=0;i<pos-1;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    printf("Node deleted from the middle.\n");
    }



int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    
    printf("Data in the list: ");
    displayList();
    printf("Inserting a new node at the beginning...\n");
    insertAtBeginning(); // Insert at the beginning of the list
    
    printf("Data in the list after insertion: ");
    displayList();

    printf("Inserting a new node at the end...\n");
    insertAtEnd(); // Insert at the end of the list

    printf("Data in the list after insertion: ");
    displayList();

    printf("Inserting a new node in the middle...\n");
    insertAtMiddle(); // Insert in the middle of the list

    printf("Data in the list after insertion: ");
    displayList();

    printf("Deleting a node from the start...\n");
    deleteAtStart(); // Delete from the start of the list

    printf("Data in the list after deletion: ");
    displayList();

    printf("Deleting a node from the end...\n");
    deleteAtEnd(); // Delete from the end of the list
    
    printf("Data in the list after deletion: ");
    displayList();

    printf("Deleting a node from the middle...\n");
    deleteAtBtw(); // Delete from the middle of the list

    printf("Data in the list after deletion: ");
    displayList();
     
    
    return 0;
}