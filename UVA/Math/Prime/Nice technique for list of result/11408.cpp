#include<stdio.h>
#include<math.h>
#define SIZE 5000500
bool prime[SIZE],s[SIZE];
long a[3000],c,d[SIZE];
bool fac(long n)
{
     bool flag=0;
	long j,prev,sum=0;
	for(j=0;j<c&&a[j]<n&&prime[n];)
	{
	     if(n%a[j]==0)
		{
			 if(!flag)
			   flag=1;
	         else if(a[j]!=prev)
	           sum+=prev;
            prev=a[j];
			 n/=a[j];
		}
		else
			j++;
	}
	sum+=prev;
	if(n!=1&&prev!=n)
		sum+=n;
	return (prime[sum]==1)?0:1;
}
void sieve(long n)
{
	long i,j;
	long m=sqrt(n);
	for(i=4;i<=n;i+=2)
		prime[i]=1;
	a[0]=2;
	c=1;
	for(i=3;i<=n;i+=2)
	{
		if(!prime[i])
		{
            if(i<2238)         
			  a[c++]=i;
			if(m>=i)
				for(j=i*i;j<=n;j+=2*i)
					prime[j]=1;
		}
	}
	d[2]=1;s[2]=1;
	for(i=3;i<=5000000;i++)
	{
        if(!prime[i])
        {
          s[i]=1;
          d[i]=d[i-1]+1;
        }
       else if(fac(i))
       {
         s[i]=1;
         d[i]=d[i-1]+1;
       }
         else
          d[i]=d[i-1];
    }
}
int main()
{
    long a,b;
    sieve(5000000);
    while(scanf("%ld",&a)==1&&a)
    {
       scanf("%ld",&b);
       if(s[a])
       printf("%ld\n",d[b]-d[a]+1);
       else
       printf("%ld\n",d[b]-d[a]);
       
    }
    return 0;
}
