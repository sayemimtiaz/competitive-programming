#include<stdio.h>
#include<math.h>
int p[1000000],f[1000000];
void seive()
{
	long i,j,m;
	m=100000;
	m=sqrt(m);
	for(i=2;i<=m;i++)
	{
		if(p[i]==0)
		{
			for(j=i*i;j<=100000;j+=i)
				p[j]=1;
		}
	}
}
long num_fac(long n)
{
	long i,count=0;
	i=2;
	while(i<=n)
	{
		if(n%i==0&&p[i])
		{
			count++;
			n/=i;
			i=2;
			continue;
		}
		if(i==2)
			i=3;
		else
			i+=2;
	}
	return count;
}
int main()
{
	seive();
	long n,i,j;
	f[1]=0;
	for(i=2;i<=100000;i++)
	{
		j=num_fac(i);
		f[i]=f[i-1]+j;
	}
	while(scanf("%ld",&n)==1)
	{
		printf("%ld\n",f[n]);
	}
	return 0;
}