#include<stdio.h>
long a[120][120];
long long s[120][120];
int main()
{
    long i,j,k,l,n;
    long long max,m;
    bool flag;
    while(scanf("%ld",&n)==1)
    {
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         scanf("%ld",&a[i][j]);
       for(i=0;i<=n;i++)
       {s[i][0]=s[0][i]=0;}
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        flag=0;
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         for(k=1;k<=n;k++)
          for(l=1;l<=n;l++)
           if(i<=k&&j<=l)
           {
            m=s[k][l]-s[k][j-1]-s[i-1][l]+s[i-1][j-1];
            if(!flag){flag=1;max=m;}
            else if(max<m)
             max=m;
            }
         printf("%lld\n",max);
    }
    return 0;
}
