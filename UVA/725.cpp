#include<stdio.h>
bool isuniq(long n1,long n2)
{
     long a,i;
     bool flag[11]={0};
     if(n2<10000)
     flag[0]=1;
     while(n1)
     {
       a=n1%10;
       if(flag[a])
        return 0;
     flag[a]=1;
       n1/=10;
     }
     while(n2)
     {
       a=n2%10;
       if(flag[a])
        return 0;
       flag[a]=1;
       n2/=10;
     }
     return 1;
}
int main()
{
    long i,a,n;
    bool flag=0;
    while(scanf("%ld",&n)==1&&n)
    {
       if(flag)
        printf("\n");
       else
        flag=1;
       bool got=0;
       for(i=10234;i<=98765;i++)
        if(i%n==0)
        {
          a=i/n;
          if(a>999)
           if(isuniq(i,a))
           {got=1; printf("%.5ld / %.5ld = %ld\n",i,a,n);}
        }
       if(!got)
        printf("There are no solutions for %ld.\n",n);
    }
    return 0;
}
