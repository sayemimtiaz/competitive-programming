#include<stdio.h>
#include<math.h>
#define SIZE 1000100
long a[SIZE],c,s[SIZE];
bool flag[SIZE];
void sieve(long n)
{
	long i,j;
	long m=sqrt(n);
	flag[0]=flag[1]=1;
	for(i=4;i<=n;i+=2)
		flag[i]=1;
	a[0]=2;
	c=1;
	for(i=3;i<=n;i+=2)
	{
		if(flag[i]==0)
		{
			a[c++]=i;
			if(m>=i)
			{
				for(j=i*i;j<=n;j+=2*i)
					flag[j]=1;
			}
		}
	}
}
long fac(long n)
{
	long j,cnt=0;
	for(j=0;j<168&&a[j]<=n;)
	{
	     if(n%a[j]==0)
		{
			 cnt++;
			n/=a[j];
		}
		else
			j++;
	}
	if(n!=1)
		cnt++;
	return cnt;
}
int main()
{
	long cnt,i,n;
	sieve(1000000);
	for(i=2;i<=1000000;i++)
	{
		if(flag[i])
		    s[i]=fac(i);
		else
			s[i]=1;
		s[i]+=s[i-1];
	}
	printf("%ld\n",a[1000]);
	while(scanf("%ld",&n)==1)
	{
		printf("%ld\n",s[n]);
	}
	return 0;
}
