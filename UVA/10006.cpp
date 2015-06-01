#include<stdio.h>
#include<math.h>
int isprime(long n)
{
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	if(n%2==0)
		return 0;
	for(long i=3;i<=sqrt(n);i+=2)
		if(n%i==0)
			return 0;
		return 1;
}
int main()
{
	long n,b,i,j,k,a[10000],count;
	int yes,flag;
	while(scanf("%ld",&n)==1)
	{
		if(n==0)
			break;
		b=n;
		yes=1;
		if(isprime(n))
		{
			count=2;
			yes=0;
		}
		else
		{
			int t;
			j=0;
			i=2;
			count=0;
			while(i<=n)
			{
				t=0;
				if(isprime(n))
				{
					i=n;
					t=1;
				}
				if((n%i==0&&isprime(i))||t)
				{
					count++;
					a[j]=i;
					j++;
					flag=0;
					if((b-1)%(i-1)!=0)
					{
						yes=0;
						break;
					}
					for(k=0;k<j-1;k++)
						if(i==a[k])
						{
							flag=1;
							break;
						}
						if(flag)
						{
							yes=0;
							break;
						}
						if(t)
							break;
						n/=i;
						i=2;
						continue;
				}
				if(i==2)
					i++;
				else
					i+=2;
			}
		}
		if(yes&&count>=3)
			printf("The number %ld is a Carmichael number.",b);
		else
			printf("%ld is normal.",b);
		printf("\n");
	}
	return 0;
}



