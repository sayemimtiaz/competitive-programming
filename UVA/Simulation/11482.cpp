#include<stdio.h>
#include<string.h>

int main()
{
    int n,m,ls,i,j,l,k,a,kas=1;
    while(scanf("%d %d",&m,&n)&&(n||m))
    {
      ls=n*m-1;
      printf("Triangular Museum %d\n",kas++);
      for(k=1;k<=n;k++)
      {
        a=2*(m-1);
       for(i=1;i<m;i++)
       {
         for(j=1;j<=ls;j++)
          printf(" ");
         for(l=1;l<=k;l++)
         {
         printf("/");
         for(j=2*(i-1);j>0;j--)
          printf(" ");
         printf("\\");
         for(j=a;l!=k&&j>0;j--)
          printf(" ");
          }
         a-=2;
         printf("\n");
         ls--;
       }
     for(j=1;j<=ls;j++)
          printf(" ");
         for(l=1;l<=k;l++)
         {
         printf("/");
         for(j=2*(m-1);j>0;j--)
          printf("_");
         printf("\\");
         }
         printf("\n");
       ls--;
      }
      printf("\n");
    }
    return 0;
}
