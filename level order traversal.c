#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* tree;
struct qnode
{
    struct node* nodeptr;
    struct qnode* link;
};
typedef struct qnode* queue;
queue front=NULL,rear=NULL;
tree insert(tree root,int x)
{
    if(root==NULL)
    {
        tree temp=malloc(sizeof(struct node));
        temp->data=x;
        temp->left=NULL;
        temp->left=NULL;
        return temp;
    }
    else if(x<=root->data)
    {
        root->left=insert(root->left,x);
    }
    else
    {
        root->right=insert(root->right,x);

    }
    return root;

}
void inorder(tree root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void qpush(tree tretemp)
{
  queue temp=malloc(sizeof(struct qnode));
  temp->nodeptr=tretemp;
  temp->link=NULL;
  if(rear==NULL)
  {
   rear=temp;
   front=temp;
   return;
  }
  rear->link=temp;
  rear=temp;
}
void levelorder(tree root)
{
  qpush(root);
  tree current;
  while(front!=NULL)
  {
    current=front->nodeptr;
    printf("%d ",current->data);
    if(current->left!=NULL)
        qpush(current->left);
    if(current->right!=NULL)
        qpush(current->right);
    front=front->link;
    free(current);
  }
}
void main()
{
  tree root=NULL;
  int i,x,n;
  printf("\nEnter the Number of elements to be inserted :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      printf("\nEnter the Element %d :",i+1);
      scanf("%d",&x);
      root=insert(root,x);
  }
  if(root==NULL)
  {
      printf("\nThe tree is Empty!!\n");
      return;
  }
  printf("\nINORDER TRAVERSAL OF BST     : ");
  inorder(root);
  printf("\nLEVEL ORDER TRAVERSAL OF BST : ");
  levelorder(root);
  printf("\n");
}
