#include<stdio.h>
#include<string.h>
long a[150][150];
long s[150][150];
int main()
{
    long i,j,k,l,r,c;
    long max,m;
    bool flag;
    while(scanf("%ld %ld",&r,&c)==2&&(r||c))
    {
         for(i=1;i<=r;i++)
           for(j=1;j<=c;j++)
            {scanf("%ld",&a[i][j]);if(a[i][j])a[i][j]=0;else a[i][j]=1;}
       for(i=0;i<=r;i++)
       s[0][i]=0;
       for(i=1;i<=c;i++)
       s[i][0]=0;
       for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
         s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
       flag=0;
       max=0;
       for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
         for(k=1;k<=r;k++)
          for(l=1;l<=c;l++)
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
