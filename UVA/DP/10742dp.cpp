#include<stdio.h>
#include<math.h>
#define SIZE 1000000
bool flag[SIZE];
long a[SIZE],c,how[SIZE];
void sieve(long n)
{
	long i,j,b;
	long m=sqrt(n);
	for(i=4;i<=n;i+=2)
		flag[i]=1;
	a[0]=2;c=1;
	for(i=3;i<=n;i+=2)
	{
		if(!flag[i])
		{
			a[c++]=i;
			if(i<=m)
			{
				for(j=i*i;j<=n;j+=2*i)
					flag[j]=1;
			}
		}
	}
	how[1]=0;
	for(i=2;i<=n;i++)
	{
		b=0;
		if(!flag[i])
			b=1;
		how[i]=how[i-1]+b;
	}
}
int main()
{
	long i,sum,ng,ager,b,kas=1;
	sieve(1000000);
	while(scanf("%ld",&ng)==1&&ng)
	{
		sum=0;
		ager=0;
		for(i=0;i<c&&a[i]<=ng;i++)
		{
			b=how[ng-a[i]]-(ager+1);
			if(b<=0)
				break;
			sum+=how[ng-a[i]]-(ager+1);
			ager++;
		}
		printf("Case %ld: %ld\n",kas++,sum);
	}
	return 0;
}