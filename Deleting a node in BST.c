#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* tree;
tree insert(tree root,int x)
{
    if(root==NULL)
    {
        tree temp=malloc(sizeof(struct node));
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else if(x<root->data)
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
        return NULL;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
tree deletenode(tree root,int x)
{
    if(root==NULL)
    {
        printf("\nElement not found!!\n");
        return NULL;
    }
    else if(x<root->data)
    {
        root->left=deletenode(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=deletenode(root->right,x);
    }
    else
    {
        if((root->left==NULL)&&(root->right==NULL))
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            tree temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            tree temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            root->data=findmin(root->right);
            root->right=deletenode(root->right,root->data);
        }
    }
   return root;
}
int findmin(tree root)
{
    tree temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp->data;
}
void main()
{
    tree root=NULL;
    int n,x,i;
    printf("\nEnter the number of elements :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the element %d :",i+1);
        scanf("%d",&x);
        root=insert(root,x);
    }
    printf("\nThe inorder Traversal of the tree is ");
    inorder(root);
    printf("\n\nEnter the element you want to Delete :");
    scanf("%d",&x);
    root=deletenode(root,x);
    printf("The inorder Traversal of the tree is ");
    inorder(root);
    printf("\n");
}
