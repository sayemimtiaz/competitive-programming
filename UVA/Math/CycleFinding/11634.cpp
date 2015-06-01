#include<stdio.h>

int memo[10000];

int f(int n)
{
    if(memo[n]!=-1)
     return memo[n];
    int digit[10],i,j,k,a;
    a=n;
    n=n*n;
    i=0;
    while(n)
    {
      digit[i++]=n%10;
      n/=10;
    }
    
    for(;i<8;i++)
     digit[i]=0;
    k=1000;
    n=0;
    for(j=5;j>=2;j--)
     n+=(digit[j]*k),k/=10;
    return (memo[a]=n); 
}

int main()
{
    int n,tortoise,cnt,hare,i;
    while(scanf("%d",&n)&&n)
    {
      for(i=0;i<=10000;i++)
       memo[i]=-1;
      bool flag[10000]={0};
      tortoise=n;
      hare=f(tortoise);
      if(hare!=tortoise)
       cnt=2;
      else
       cnt=1;
     // flag[tortoise]=flag[hare]=1;
     while(tortoise!=hare)
      {
        tortoise=f(tortoise);
        hare=f(hare);
       /* if(!flag[hare])
         {cnt++;
        flag[hare]=1;}*/
        hare=f(hare);
        /*if(!flag[hare])
        {cnt++;
         flag[hare]=1;}*/
         cnt++;
      }
      hare=f(hare);
      int lp=1;
      while(tortoise!=hare)
      {
        
      }
      printf("%d\n",cnt);
    }
    return 0;
}
