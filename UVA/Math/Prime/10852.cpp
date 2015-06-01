#include<stdio.h>
#include<math.h>
#define SIZE 11000
bool prime[SIZE];
long a[SIZE],c;
void sieve(long N)
{
     long i,j;
     long M=sqrt(N);
	for(i=4;i<=N;i+=2)
		prime[i]=1;
	a[0]=2;c=1;
	for(i=3;i<=N;i+=2)
		if(!prime[i])
		{
            a[c++]=i;
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
        }
}
int main()
{
    long i,n,save,max,p,kase;
    sieve(11000);
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld",&n);
       max=-1999;
       for(i=0;i<c&&a[i]<=n;i++)
       {
          p=n/a[i];
          p=n-(p*a[i]);
          if(p>max)
          {max=p;save=a[i];}
       }
       printf("%ld\n",save);
    }
    return 0;
}
