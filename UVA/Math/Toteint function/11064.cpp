#include<stdio.h>
#include<math.h>
#define SIZE 50000
long long c,a[SIZE];
bool prime[SIZE];
long long fac(long long n)
{
     long long i,prev,div=1,fr=0;
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
               {div*=(fr+1);s*=(1-(1/(double)prev));fr=0;}          
               prev=a[i];
               fr++;
               n/=a[i];
            }
            else
              i++;
      }
      div*=(1+fr);
      if(flag)
      s*=(1-(1/(double)prev));
      if(n!=1)
       {div*=2;s*=(1-(1/(double)n));}
      return (div-1+s);
}
void sieve(long long N)
{
     long long i,j;
     long long M=sqrt(N);
	for(i=4;i<=N;i+=2)
		prime[i]=1;
	a[0]=2;c=1;
	for(i=3;i<=N;i+=2)
		if(!prime[i])
		{
            a[c++]=i;
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
}
int main()
{
    long long i,n;
    sieve(46342);
    while(scanf("%lld",&n)==1)
    {
        if(n==1)                        
        {printf("0\n");continue;}
        n=n-fac(n);
        printf("%lld\n",n);
    }
    return 0;
}
