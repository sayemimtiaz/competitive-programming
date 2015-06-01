#include<stdio.h>
#include<math.h>
#define SIZE 1000000
bool prime[SIZE];
long sa[SIZE],sb[SIZE];
int main()
{
	long m=999999,i,j,cnt,n,b;
	m=sqrt(m);
	for(i=4;i<SIZE;i+=2)
		prime[i]=1;
	prime[0]=prime[1]=1;
	for(i=3;i<SIZE;i+=2)
	{
		if(!prime[i])
		{
			if(m>=i)
			for(j=i*i;j<SIZE;j+=2*i)
				prime[j]=1;
		}
	}
	for(i=6;i<SIZE;i+=2)
	{
		for(j=2;j<=(i/2);j++)
		{
			b=i-j;
			if(!prime[j]&&!prime[b])
			{
				sa[i]=j;sb[i]=b;
				break;
			}
		}
	}
	while(1)
	{
		scanf("%ld",&n);
		if(n==0)
			break;
		if(sa[n])
		printf("%ld = %ld + %ld\n",n,sa[n],sb[n]);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}


