#include<stdio.h>
#include<string.h>

int main()
{
    int kase,E[10][10],i,j,k;
    scanf("%d",&kase);
    while(kase--)
    {
      memset(E,0,sizeof(E));
      for(i=0;i<9;i+=2)
        for(j=0;j<=i;j+=2)
         scanf("%d",&E[i][j]);
     for(i=1;i<9;i+=2)
     {
       for(j=0;j<=i;j+=2)
       {
         E[i+1][j+1]=(E[i-1][j]-E[i+1][j]-E[i+1][j+2])/2;
         E[i][j]=E[i+1][j]+E[i+1][j+1];
         E[i][j+1]=E[i+1][j+2]+E[i+1][j+1];
       }
     }
     for(i=0;i<9;i++,printf("\n"))
     {
       printf("%d",E[i][0]);
       for(j=1;j<=i;j++)
        printf(" %d",E[i][j]);
    }
   }
    return 0;
}
