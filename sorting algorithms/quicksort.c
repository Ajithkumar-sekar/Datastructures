#include<stdio.h>
void quicksort(int* a,int start,int end)
{
    if(start>=end)
        return;
    int p_index=partition(a,start,end);
    quicksort(a,start,p_index-1);
    quicksort(a,p_index+1,end);
}
int partition(int* a,int start,int end)
{
    int pivot=a[end];
    int p_index=start;
    int i,temp;
    for(i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
           temp=a[p_index];
           a[p_index]=a[i];
           a[i]=temp;
           p_index++;
        }
    }
    temp=a[p_index];
    a[p_index]=a[end];
    a[end]=temp;
    return p_index;
}
void print(int a[],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
}
void main()
{
    int n,i;
    printf("\nEnter the number of elements :");
    scanf("%d",&n);
    int* a=(int)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("\nEnter the element %d :",i+1);
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("\nAfter sort :");
    print(a,n);
}
