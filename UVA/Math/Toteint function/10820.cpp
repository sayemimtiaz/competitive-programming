#include<stdio.h>
#include<math.h>
#define SIZE 500
long c,a[SIZE];
long long d[60000];
bool prime[SIZE];
double fac(long long n)
{
     long i,prev;
     bool flag=0;
     double s;
     s=n;
     for(i=0;i<c&&a[i]<=n;)
      {
            if(n%a[i]==0)
            {
               if(!flag)
                 flag=1;
               else if(prev!=a[i])
                 s*=(1-(1/(double)prev));          
               prev=a[i];
               n/=a[i];
            }
            else
              i++;
      }
      if(flag)
      s*=(1-(1/(double)prev));
      if(n!=1)
       s*=(1-(1/((double)n+eps)));
      return s;
}
void sieve(long N)
{
     long i,j;
     long M=sqrt(N);
	for(i=4;i<=N;i+=2)
		prime[i]=1;
	a[0]=2;c=1;
	for(i=3;i<=N;i+=2)
	{
		if(!prime[i])
		{
            a[c++]=i;
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
	}
}
int main()
{
    long long n,r,nr,p,i;
    sieve(230);
    d[1]=1;
    for(i=2;i<=50000;i++)
    {
       r=fac(i);
       d[i]=d[i-1]+2*r;
    }
    while(scanf("%lld",&n)==1&&n)
    {
        printf("%lld\n",d[n]);
    }
    return 0;
}
