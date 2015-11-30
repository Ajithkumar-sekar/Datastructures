#include<stdio.h>
void main()
{
    int i,n,hole,value;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    int* a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("\nElement %d :",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nThe elements before sorted:-\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\n");
    for(i=1;i<n;i++)
    {
        value=a[i];
        hole=i;
        while((hole!=0)&&(a[hole-1]>value))
        {
            a[hole]=a[hole-1];
            hole--;
        }
        a[hole]=value;
    }
    printf("Elements in sorted order:-\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
