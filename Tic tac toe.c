#include<stdio.h>
#include<time.h>
 char mat[10][10];
 int checkwin(int n)
 {
    int i,j,k;
    char a[10];
    for(i=0;i<n;i++)//chechrows
    {
      for(j=0;j<n;j++)
      {
      a[j]=mat[i][j];
      }
      if(checksame(a,n))
        {
            printf("\nROW=%d",i+1);
            return 1;
        }
    }
    for(i=0;i<n;i++)//checkcolumns
    {
      for(j=0;j<n;j++)
      {
        a[j]=mat[j][i];
       }
        if(checksame(a,n))
        {
            printf("\nCOLOUMN=%d",i+1);
            return 1;
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
       a[i]=mat[i][i];

    }
       if(checksame(a,n))
       {
         printf("\nDIAGONAL-LEFT\n");
         return 1;
       }

     for(i=0,j=n-1;i<n;i++,--j)
    {

      a[i]=mat[i][j];//cross diagonal(right)

    }
    if(checksame(a,n))
    {
      printf("\nCROSS DIAGONAL-RIGHT\n");
      return 1;
    }
    else
      return 0;
 }
int checksame(char a[],int n)
{
    int i=0;
 while((a[0]==a[i])&&(i<n)&&(a[i]!='0'))
 {
     i++;
 }
 if(i==n)
    return 1;
 else
    return 0;
}
int checkdraw(int n)
{
    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]!='0')
            {
                k++;
            }
        }
    }
    if(k==n*n||k==n*n-1||k==n*n-2)
        return 1;
    else
        return 0;
}
void print(int n)
{
    int i,j,k=0;
    printf("\nThe matrix data :\n");
    printf("\t\t\t\t     ");
    for(k=0;k<n;k++)
        printf("%d   ",k+1);
    printf("\n\n");
   for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          if(j==0)
          {
              printf("\t\t\t\t %d   ",i+1);
          }
         printf("%c   ",mat[i][j]);
      }
      printf("\n\n");
    }
}
void main()
{
    int n,i=0,j,k=0;
    char player1[20],player2[20],p1,p2;
    printf("\nEnter the name of the player1 :");
    gets(player1);
    printf("Your code is %c\n",p1=player1[0]);
    printf("\nEnter the name of the player2 :");
    gets(player2);
    while(player1[0]==player2[i])
    {
        i++;
    }
    printf("Your code is %c\n",p2=player2[i]);
    p:
    printf("\nEnter 3 for 3*3 Matrix,4 for 4*4 Matrix ...:");
    scanf("%d",&n);
    if((n<3)||(n>10))
    {
        printf("\nPlease enter the value greater than and less than 10!!!\n");
        goto p;
    }
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          mat[i][j]='0';
      }
    }
    print(n);
  while(1)
  {
   printf("\nPlayer1(%s) Enter the data :",player1);
   scanf("%d %d",&i,&j);
   system("cls");
   if(mat[i-1][j-1]=='0')
     mat[i-1][j-1]=p1;
   else
   printf("\nplayer1 Data over ridding!! ,%s missed a chance!!\n",player1);
   print(n);
   if(checkwin(n))
   { system("color 79");
     printf("\n\t\t\t %s Won the match!!\n",player1);
     break;
   }
   if(checkdraw(n))
   {   system("color 0a");
       printf("\n\n\t\tMatch Draw!!");
       break;
   }
   printf("\nPlayer2(%s) Enter the data :",player2);
   scanf("%d %d",&i,&j);
   system("cls");
   if(mat[i-1][j-1]=='0')
     mat[i-1][j-1]=p2;
   else
     printf("\nplayer2 Data over ridding!! ,%s missed a chance!!\n",player2);
   print(n);
   if(checkwin(n))
   {
       system("color 79");
     printf("\n\t\t\t %s Won the match!!\n",player2);
     break;
   }
    if(checkdraw(n))
   {   system("color 0a");
       printf("\n\n\t\tMatch Draw!!");
       break;
   }
  }

}
