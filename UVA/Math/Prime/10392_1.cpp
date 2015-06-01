#include<stdio.h>
#include<math.h>
#define SIZE 1000500
long a[SIZE];
long c;
bool prime[SIZE];
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
    long  long n;
    long i;
    sieve(1000004);
    while(scanf("%lld",&n)&&n>=0)
    {
        for(i=0;i<c&&a[i]<n;)
          {
            if(n%a[i]==0)
            {
               printf("%4c%ld\n",' ',a[i]); 
               n/=a[i];
            }
            else
              i++;
        }
        
        printf("%4c%lld\n",' ',n);
       printf("\n");
    }
    return 0;
}
