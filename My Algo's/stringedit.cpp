#include<stdio.h>
#include<string.h>
//Cost of Insert
#define II 1
//Cost of delete
#define DD 1
char X[1000],Y[1000];
int s[1000][1000],cost[1000][1000];
void print(int i,int j)
{
     if(i==0||j==0)
       return;
     if(s[i][j]==3)
     {
        print(i-1,j-1);
        printf("Replace %dth character '%c' of X with %dth character '%c'\n",i,X[i-1],j,Y[j-1]);
     }
     else if(s[i][j]==2)
     {
          print(i-1,j);
          printf("Delete %dth character '%c' of X\n",i,X[i-1]);
     }
     else
      {
          print(i,j-1);
          printf("Insert %dth character '%c' of Y into %dth position of X\n",j,Y[j-1],i);
     }
} 
int main()
{
    int i,j,m,n,kase,RR;
    bool flag;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
    gets(X);
    gets(Y);
    m=strlen(X);
    n=strlen(Y);
    cost[0][0]=0;
    for(i=1;i<=n;i++)
      cost[0][i]=cost[0][i-1]+II;
    for(i=1;i<=m;i++)
      cost[i][0]=cost[i-1][0]+DD;
    for(i=1;i<=m;i++){
      for(j=1;j<=n;j++)
      {
          RR=(X[i-1]==Y[j-1])?0:2;
          flag=((cost[i-1][j]+DD)<(cost[i][j-1]+II))?1:0;
          if(flag)
          {
             flag=((cost[i-1][j]+DD)<(cost[i-1][j-1]+RR))?1:0;
             cost[i][j]=(flag==1)?(cost[i-1][j]+DD):(cost[i-1][j-1]+RR);
             s[i][j]=(flag==1)?2:3;
          }
          else
          {
             flag=((cost[i][j-1]+II)<(cost[i-1][j-1]+RR))?1:0;
             cost[i][j]=(flag==1)?(cost[i][j-1]+II):(cost[i-1][j-1]+RR);
             s[i][j]=(flag==1)?1:3;
          }
          printf("%d",cost[i][j]);
      }
      printf("\n");
      }
    printf("%d\n",cost[m][n]);
    //print(m,n);
    }
    return 0;
}
