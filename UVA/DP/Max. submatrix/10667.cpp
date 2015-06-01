#include<stdio.h>
#include<string.h>
long a[150][150];
long s[150][150];
int main()
{
    long i,j,k,l,r1,c1,ss,r2,c2,kase,n;
    long max,m;
    bool flag;
    scanf("%ld",&kase);
    while(kase--)
    {
         scanf("%ld %ld",&n,&ss);
           for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
             a[j][k]=1;
         for(i=1;i<=ss;i++)
         {
           scanf("%ld %ld %ld %ld",&r1,&c1,&r2,&c2);
           for(j=r1;j<=r2;j++)
            for(k=c1;k<=c2;k++)
               a[j][k]=0;
         }     
       for(i=0;i<=n;i++)
       s[0][i]=0;
       for(i=1;i<=n;i++)
       s[i][0]=0;
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
       flag=0;
       max=0;
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         for(k=1;k<=n;k++)
          for(l=1;l<=n;l++)
           if(i<=k&&j<=l)
           {
            m=s[k][l]-s[k][j-1]-s[i-1][l]+s[i-1][j-1];
            if(m==(l-j+1)*(k-i+1))
            {
            if(!flag){flag=1;max=m;}
            else if(max<m)
             max=m;
            }
            }
         printf("%ld\n",max);
    }
    return 0;
}
