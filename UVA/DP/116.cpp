#include<stdio.h>
#include<string.h>
long r,c,grid[110][110],A[110][110],s[110][110];
void print(long i,long j)
{
     if(i==0||j==c+1)
       return;
     if(j!=1)
      printf(" ");
     printf("%ld",i);
     if(s[i][j]==4)
       print(r,j+1);
     else if(s[i][j]==5)
       print(1,j+1);
     else if(s[i][j]==1)
       print(i,j+1);
     else if(s[i][j]==2)
       print(i+1,j+1);
     else if(s[i][j]==3)
       print(i-1,j+1);
}
int main()
{
    long i,j,min;
    while(scanf("%ld %ld",&r,&c)==2)
    {
      for(i=1;i<=r;i++)
       for(j=1;j<=c;j++)
         scanf("%ld",&grid[i][j]);
      memset(A,0,sizeof(A));
      for(j=c;j>=1;j--)
        {for(i=r;i>=1;i--)
        {
          if(r==1)
          {
           A[i][j]=A[i][j+1];s[i][j]=1;
          }
          else if(i==1)
          {
          if(A[i][j+1]>A[i+1][j+1])
           {A[i][j]=A[i+1][j+1];s[i][j]=2;}
          else
           {A[i][j]=A[i][j+1];s[i][j]=1;}
           if(A[r][j+1]<A[i][j])
           {A[i][j]=A[r][j+1];s[i][j]=4;}
          }
          else if(i==r)
          {
          if(A[i-1][j+1]<A[1][j+1])
          {A[i][j]=A[i-1][j+1];s[i][j]=3;}
          else
           {A[i][j]=A[1][j+1];s[i][j]=5;}
           if(A[i][j+1]<A[i][j])
            {A[i][j]=A[i][j+1];s[i][j]=1;}
          }
          else
          {
          if(A[i-1][j+1]>A[i][j+1])
           {A[i][j]=A[i][j+1];s[i][j]=1;}
          else
           {A[i][j]=A[i-1][j+1];s[i][j]=3;}
           if(A[i+1][j+1]<A[i][j])
            {A[i][j]=A[i+1][j+1];s[i][j]=2;}
          }
          A[i][j]+=grid[i][j];
        }
        }
      min=A[1][1];j=1;
      for(i=2;i<=r;i++)
       if(A[i][1]<min)
       {
         min=A[i][1];
         j=i;}
       print(j,1);
       printf("\n%ld\n",min);
    }
    return 0;
}
