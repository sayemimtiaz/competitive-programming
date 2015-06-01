#include<stdio.h>
#include<math.h>
long a[1000000],c;
bool flag[1000000];
void sieve(long n)
{
	long i,j,r;
	long m=sqrt(n);
	a[0]=2;
	c=1;
	flag[0]=flag[1]=1;
	for(i=4;i<=n;i+=2)
		flag[i]=1;
	for(i=3;i<=n;i+=2)
	{
		if(flag[i]==0)
		{
			a[c++]=i;
			if(m>=i)
			{
				r=i+i;
				for(j=i*i;j<=n;j+=r)
					flag[j]=1;
			}
		}
	}
}
long digit(long n)
{
	long sum=0;
	while(n)
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int main()
{
	long sumDigit,oriSum,i,j,b,n,kase;
	sieve(35000);
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		for(j=n+1;;j++)
		{
			oriSum=digit(j);
			sumDigit=0;
			b=j;
		for(i=0;i<c&&a[i]<b;)
		{
			if(b%a[i]==0)
			{
				sumDigit+=digit(a[i]);
				b/=a[i];
			}
			else
				i++;
		}
		if(b!=1&&b!=j)
			sumDigit+=digit(b);
		if(sumDigit==oriSum)
		{
			printf("%ld\n",j);
			break;
		}
		}
	}
		return 0;
}