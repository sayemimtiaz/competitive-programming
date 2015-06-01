#include<stdio.h>
#include<math.h>
#define SIZE  1048690
bool B[SIZE],flag[SIZE];
void sieve(long n)
{
    long k,i,j;
    k=sqrt(n);
    for(i=4;i<=n;i+=2)
        flag[i]=1;
    for(i=3;i<=k;i+=2)
    {
       if(!flag[i])
         for(j=i*i;j<=n;j+=2*i)
                 flag[j]=1;
    }
}
void boka(long n)
{
    long k,i,j,cnt=0;
    k=n/2;
     for(i=4;i<=k;i++)
     {
       if(flag[i]&&!B[i])
       {
        for(j=2*i;j<=n;j+=i)
         B[j]=1;
        
        }
     }
    // printf("%ld\n",cnt);
}
int main()
{
    long K,cnt,a;
    sieve(1048590);
    boka(1048590);
    while(~scanf("%ld",&K))
    {
      cnt=0;
      while(K--)
      {
        scanf("%ld",&a);
        if(flag[a]&&!B[a])
         cnt++;
      }
      printf("%ld\n",cnt);
    }
    return 0;
}
