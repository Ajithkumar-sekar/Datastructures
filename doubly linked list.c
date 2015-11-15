#include<stdio.h>
struct node
{
    int data;
    struct node* pre;
    struct node* next;
};
struct node* head;
typedef struct node* dlist;
dlist* getnode(int x)
{
    dlist newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->pre=NULL;
    newnode->next=NULL;
    return newnode;
}
void insert(int x)
{
    dlist newnode=getnode(x);
    if(head==NULL)
    {
       head=newnode;
       return;
    }
    newnode->next=head;
    head->pre=newnode;
    head=newnode;
}
void print()
{
    dlist temp=head;
    printf("\nList is ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse()
{
    printf("\nThe reversed linked list is ");
    dlist temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->pre;
    }
    printf("\n");

}
int main()
{
    head=NULL;
    int i,x,n;
    printf("\nEnter the number of elements :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the element :");
        scanf("%d",&x);
        insert(x);
        print();
    }
    reverse();
}
