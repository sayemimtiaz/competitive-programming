#include<stdio.h>
#include<string.h>
long a[50][50];
long s[50][50];
int main()
{
    char str[1000];
    long i,j,k,l,n,kase;
    long max,m;
    bool flag,blank=0;
    scanf("%ld",&kase);
    getchar();
    while(kase--)
    {
         getchar();
         gets(str);
         n=strlen(str);
         for(i=1;i<=n;i++)
          a[1][i]=str[i-1]-'0';
         for(i=2;i<=n;i++)
         {
           gets(str);
           for(j=1;j<=n;j++)
            a[i][j]=str[j-1]-'0';
         }
       for(i=0;i<=n;i++)
       {s[i][0]=s[0][i]=0;}
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
          if(blank)
           printf("\n");
          blank=1;
         printf("%ld\n",max);
    }
    return 0;
}
