#include<stdio.h>
struct snode
{
    char name[15];
    struct snode* next;
};
typedef struct snode* student;
student shead;

struct gnode
{
    char sports[10];
    int nostd;
    struct snode* link;
};
typedef struct gnode* group;
group sprtgrps[10];
group ghead;

group createnode()
{
    group temp=malloc(sizeof(struct gnode));
    printf("\nEnter the name of the sports :");
    scanf("%s",&temp->sports);
    temp->link=NULL;
}
void insert_student(int p)
{
    int i,n;
    printf("\nEnter the number of students:");
    scanf("%d",&n);
    sprtgrps[p]->nostd=n;
    for(i=0;i<n;i++)
    {
    student temp=malloc(sizeof(struct snode));
    printf("\nEnter the name of the student :");
    scanf("%s",&temp->name);
    temp->next=NULL;
    if(sprtgrps[p]->link==NULL)
    {
        sprtgrps[p]->link=temp;
    }
    else
    {
        temp->next=sprtgrps[p]->link;
        sprtgrps[p]->link=temp;
    }
    }
}
printdetail(int n)
{
 int i;
 for(i=0;i<n;i++)
 {
     printf("\nFor sports %s",sprtgrps[i]->sports);
     print(sprtgrps[i]->link);
 }
}
print(group root)
{

    student temp=root;
     if(temp==NULL)
    {
        printf("\nThe list is empty!!\n\n");
        return;
    }
    // printf("\nThe list of books are  ");
    printf("\nThe students are \n\n");
    int i=1;
     while(temp!=NULL)
     {
         printf("%d) %s\n",i,temp->name);
         temp=temp->next;
         i++;
     }
     printf("\n");
}
void insert(char* name,int p)
{
    int i=0;
    student temp=malloc(sizeof(struct snode));
    //temp->name
    strcpy(temp->name,name);
    temp->next=NULL;
    if(sprtgrps[p]->link==NULL)
    {
       sprtgrps[p]->link=temp;
       return;
    }
    else
    {
        temp->next=sprtgrps[p]->link;
        sprtgrps[p]->link=temp;
    }
}
void main()
{
    ghead=NULL;
    shead=NULL;
   int i,n;
   printf("\nEnter the number of groups :");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("\nFor sports %d",i+1);
       sprtgrps[i]=createnode();
   }
   printdetail(n);
   int number;
   printf("\nEnter the number of students :");
   scanf("%d",&number);
   char name1[10];
   int a,b=0,c;
   //printf("\nNo of students %d",number);
   for(i=0;i<number;i++)
   {
       printf("\nEnter the name of the student %d :",i+1);
       scanf("%s",&name1);
       for(a=0;name1[a]!='\0';a++)
       {
           b=b+name1[a];
       }

       c=b%n;
       // printf("\n%d grp->%d nogrps->%d",b,c,n);
        printf("\nInserted into the group %s\n",sprtgrps[c]->sports);
       insert(name1,c);
       //printf("\nThe value of numer=%d and i=%d ",number,i);

   }
   /*
   for(i=0;i<n;i++)
   {
       printf("\nFor sport %s",sprtgrps[i]->sports);
       insert_student(i);
   }
   */
   printf("\nSTUDENT NAMES BASED ON THE GROUPS\n");
   printdetail(n);
}
