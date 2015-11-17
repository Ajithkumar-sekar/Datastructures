#include<stdio.h>
void quicksort(int *a,int start,int end)
{
    if(start<end)
    {
    int p_index=partition(a,start,end);
    print(a,end+1);
    quicksort(a,start,p_index-1);
    quicksort(a,p_index+1,end);
    }
}
int partition(int *a,int start,int end)
{
    int pivot=a[end];
    printf("\nPIVOT= %d",pivot);
    int p_index=start,i;
    for(i=start;i<end-1;i++)
    {
        if(a[i]<=pivot)
        {
            int temp=a[i];
            a[i]=a[p_index];
            a[p_index]=temp;
            p_index++;
        }
    }
    int temp=a[p_index];
    a[p_index]=a[end];
    a[end]=temp;
    return p_index;
}
void print(int a[],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
void main()
{
    //int n=7,i;
    int n,i;
    printf("\nEnter the number of elements :");
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
       printf("\nEnter the element %d :",i+1);
       scanf("%d",&a[i]);
    }
   // int a[]={23,76,10,-10,78,2,39};
    quicksort(a,0,n-1);
    printf("\n\nThe Elements in sorted order ");
    print(a,n);
}
