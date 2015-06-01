/*Filling A knapsack such that it must contain weight Greater than a value P and
Less than a value Q*/



#include<stdio.h>
#include<string.h>
int mm[120][10009],s[120][10009];
int main()
{
    int m,n,i,j,p[120],f[120],w1,w2,t,favor;
    while(~scanf("%d %d",&m,&n))
    {
      for(i=1;i<=n;i++)
      scanf("%d %d",&p[i],&f[i]);
      t=m+200;
      for(i=0;i<=n;i++)
      s[i][0]=1;
      for(i=1;i<=n;i++)
      {
       for(j=0;j<=t;j++)
       {
         w1=mm[i-1][j];
         if(p[i]<=j&&s[i-1][j-p[i]])
         w2=f[i]+mm[i-1][j-p[i]];
         else 
         w2=0;
         mm[i][j]=(w1>w2)?w1:w2;
         if(mm[i][j])
         s[i][j]=1;
       }
      }
      favor=0;
      for(i=0;i<=m;i++)
       favor=(favor<mm[n][i])?mm[n][i]:favor;
      for(i=2001;i<=t;i++)
       favor=(favor<mm[n][i])?mm[n][i]:favor;
      printf("%d\n",favor);
      memset(mm,0,sizeof(mm));
      memset(s,0,sizeof(s));
    }
    return 0;
}
