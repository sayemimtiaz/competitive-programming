#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long m[500][500];
bool p[500][500];
int main()
{
    char *pch,str[20000];
    bool flag=0;
    long i,j,a,b,kase,W,N;
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld %ld",&W,&N);
      getchar();
      memset(p,0,sizeof(p));
      m[1][1]=1;
      for(i=1;i<=W;i++)
      {
      gets(str);
      pch=strtok(str," ");
      a=atol(pch);
      pch=strtok(NULL," ");
      while(pch!=NULL)
      {
        b=atol(pch);
        p[a][b]=1;
        pch=strtok(NULL," ");
      }
      }
      for(i=0;i<=N;i++)
       m[0][i]=0;
      for(i=1;i<=W;i++)
       m[i][0]=0;
       j=2;
      for(i=1;i<=W;i++)
       { for(;j<=N;j++)
         m[i][j]=(p[i][j])?0:m[i-1][j]+m[i][j-1];
           j=1;
       }
        if(flag)
         printf("\n");
        else
         flag=1;
        printf("%lld\n",m[W][N]);
    }
    return 0;
}
