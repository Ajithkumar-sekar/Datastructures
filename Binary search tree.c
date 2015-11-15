#include<stdio.h>
struct node
{
    int data;
    struct node* right;
    struct node* left;
};
typedef struct node* tree;
tree insert(tree root,int x)
{
    if(root==NULL)
    {
    tree temp=malloc(sizeof(struct node));
    temp->data=x;
    printf("\n data %d",temp->data);
    temp->right=NULL;
    temp->left=NULL;
    return;
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
void preorder(tree root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(tree root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(tree root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void findmin(tree root)
{
    if(root->left==NULL)
        printf("\nThe Minimum Value in the tree is %d\n",root->data);
    else
    findmin(root->left);
}
void descending(tree root)
{
    if(root==NULL)
        return;
    descending(root->right);
    printf("%d ",root->data);
    descending(root->left);
}
void findmax(tree root)
{
    if(root->right==NULL)
        printf("\nThe Maximum Value in the tree is %d\n",root->data);
    else
        findmax(root->right);
}
int findheight(tree root)
{
    if(root==NULL)
        return -1;
    int lheight=findheight(root->left);
    int rheight=findheight(root->right);
    return (max(lheight,rheight)+1);
}
int max(int r,int l)
{
    if(r==l)
        return r;
    else if(r>l)
        return r;
    else
        return l;
}
int main()
{
  tree root=NULL;
  int i,x,n;
  printf("\nEnter the Number of elements to be Inserted :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      printf("\nEnter the element %d :",i+1);
      scanf("%d",&x);
      root=insert(root,x);
  }
 if(root==NULL)
 {
    printf("\nThe Tree is empty!!\n");
    return;
 }
 printf("\nThe tree traversals ");
 printf("\n\nPREORDER  :");
 preorder(root);
 printf("\n\nINORDER   :");
 inorder(root);
 printf("\n\nPOSTORDER :");
 postorder(root);
 printf("\n");
 printf("\nAscending order of the values :");
 inorder(root);
 printf("\nDescending order of the values:");
 descending(root);
 printf("\n");
 findmin(root);
 findmax(root);
 int height;
 height=findheight(root);
 printf("\nThe height of the tree is %d\n",height);
}
