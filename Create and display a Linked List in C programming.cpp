//Create and display a Linked List in C programming.

#include <stdio.h> 
#include <stdlib.h> 

typedef struct node
{
    int data;
    struct node * next;
}node;

node * createlinkedList(int n);
void showLinkedList(node * head);

int main() 
{ 
    
    int n;
    node * Head=NULL;
    printf("\nHow many nodes: ");
    scanf("%d",&n);
    
    Head=createlinkedList(n);
    showLinkedList(Head);
    return 0; 
} 


node * createlinkedList(int n)
{
    node * temp=NULL;
    node * p=NULL;
    node * Head=NULL;
    int i;
   
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter the data for node number %d: ",i+1);
        
        temp=(node*)malloc(sizeof(node));
        
        scanf("%d",&(temp->data));
        temp->next=NULL;
        
        if(Head==NULL) //if list is empty, then make temp as head 
        {
            Head=temp;
        }
        else
        {
            p=Head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }
    return Head;
    
}

void showLinkedList(node * head)
{
    printf("\nThe linked list is: ");
    while(head !=NULL)
    {
        printf("%d-> ",head->data);
        head=head->next;
    }
}
