#include<stdio.h>
#include<math.h>
#define SIZE 50000
long c,a[SIZE];
bool prime[SIZE];
double fac(long n)
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
      s*=(1-(1/(double)prev));
      if(n!=1)
       s*=(1-(1/(double)n));
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
    long i,n;
    sieve(32000);
    while(scanf("%ld",&n)==1&&n)
    {
        if(n==1)                        
        printf("0\n");
        else
        printf("%0.lf\n",fac(n));
    }
    return 0;
}
