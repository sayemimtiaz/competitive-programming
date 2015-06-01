#include<stdio.h>
#include<stdlib.h>
 double ncr(long n,long r)
{
     long i;
      double t,p;
     p=1;
     for(i=2;i<=n;i++)
       p*=i;
       t=1;
      for(i=2;i<=r;i++)
       t*=i;
      p/=t;
      t=1;
       for(i=2;i<=(n-r);i++)
       t*=i;
      p/=t;
      return p;
      
}
 
int main()
{
    double co;
    long kase,i,j,n,k,kas=1;
    char str[1000],a[1000],b[1000],c[1000];
    scanf("%ld",&kase);
    gets(str);
    while(kase--)
    {
           gets(str);
         for(i=0;str[i]!='(';i++);
         k=0;
         for(j=i+1;str[j]!='+';j++)
            a[k++]=str[j];
         a[k]='\0';
         k=0;
         for(i=j+1;str[i]!=')';i++)
            b[k++]=str[i];
         b[k]='\0';
         k=0;
         for(j=i+2;str[j]!='\0';j++)
            c[k++]=str[j];
         c[k]='\0';
         n=atol(c);
         printf("Case %ld: ",kas++);
         for(i=n,j=0;i>=0;i--,j++)
         {
            co=ncr(n,j);
            if(co!=1)
              printf("%0.lf*",co);
            if(i==n)
            {
              if(n==1)
              printf("%s",a);
              else
              printf("%s^%ld",a,n);
              }
            else if(i==0)
            {
                 if(n==1)
                 printf("%s",b);
                 else
              printf("%s^%ld",b,n);
              }
            else
            {
               if(i==1&&j==1) 
               printf("%s*%s",a,b);
               else if(i==1)
               printf("%s*%s^%ld",a,b,j);
               else if(j==1)
               printf("%s^%ld*%s",a,i,b);
               else
               printf("%s^%ld*%s^%ld",a,i,b,j);
            }
            if(i!=0)
              printf("+");
         }
         printf("\n");
    }
    return 0;
}
