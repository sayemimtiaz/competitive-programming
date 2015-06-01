#include<stdio.h>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a>b)?b:a
#define SIZE 10009
int main()
{
    long m,n,t,b,e,i,p[SIZE],s[SIZE],x,y;
    while(~scanf("%ld %ld %ld",&m,&n,&t))
    {
       b=MIN(m,n);
       e=MAX(m,n);
       for(i=0;i<b;i++)
       {p[i]=0;s[i]=i;}
       for(i=b;i<e;i++)
       { 
          p[i]=p[i-b]+1;
          s[i]=s[i-b];
       }
       for(i=e;i<=t;i++)
       {
         x=i-b;y=i-e;
         if(s[x]==s[y])
         {
          p[i]=MAX(1+p[x],1+p[y]);
          s[i]=s[x];
          }
         else if(s[x]<s[y])
         {
          p[i]=1+p[x];
          s[i]=s[x];
          }
         else
         {
          p[i]=1+p[y];
          s[i]=s[y];
          }
       }
       if(s[t])
       printf("%ld %ld\n",p[t],s[t]);
       else
       printf("%ld\n",p[t]);                 
    }
    return 0;
}
