#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long m[500][500];
bool p[32][32][32][32];
int main()
{
    long i,j,a,b,c,mm,nn,kase,W,N,ta,tb,sa,sb;
    char str[10000];
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld",&N);
      scanf("%ld %ld",&sa,&sb);
      scanf("%ld %ld",&ta,&tb);
      memset(p,0,sizeof(p));
      scanf("%ld",&W);
      getchar();
      for(i=1;i<=W;i++)
      {
         gets(str);
         sscanf(str,"%ld %ld %c",&a,&b,&c);
         mm=a;nn=b;
         if(c=='S'&&nn>1)
           nn=b-1;
         else if(c=='W'&&mm>1)
           mm=a-1;
         else if(c=='N'&&nn<N)
           nn=b+1;
         else if(mm<N)
           mm=a+1; 
         p[a][b][mm][nn]=p[mm][nn][a][b]=1;
      }
      for(i=0;i<=N;i++)
      { m[0][i]=0;m[i][0]=0;}
      for(i=1;i<=N;i++)
       { for(j=1;j<=N;j++)
         {
          if(i==sa&&j==sb)
           {m[i][j]=1;continue;}
           if(!p[i][j][i][j-1]&&!p[i][j][i-1][j])
            m[i][j]=m[i-1][j]+m[i][j-1];
           else if(!p[i][j][i-1][j])
            m[i][j]=m[i-1][j];
           else if(!p[i][j][i][j-1])
            m[i][j]=m[i][j-1];
            else
             m[i][j]=0;
            }
       }
        printf("%lld\n",m[ta][tb]);
    }
    return 0;
}
