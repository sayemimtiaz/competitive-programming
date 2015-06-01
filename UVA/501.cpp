#include<stdio.h>
#define SIZE 1000000
long c[SIZE],a[SIZE],yet;
void add(long n)
{
	long i,j,pos;
	pos=yet;
	for(i=0;i<yet;i++)
	{
		if(a[i]>n)
		{
			pos=i;
			for(j=yet;j>i;j--)
				a[j]=a[j-1];
			break;
		}
	}
	a[pos]=n;
	yet++;
}
int main()
{
	bool flag=0;
	long i,j,M,N,u,kase;
	scanf("%ld",&kase);
	while(kase--)
	{
		yet=0;
		scanf("%ld %ld",&M,&N);
		for(i=0;i<M;i++)
			scanf("%ld",&c[i]);
		j=0;
		for(i=0;i<N;i++)
		{
			scanf("%ld",&u);
			if(!i&&flag)
				printf("\n");
			while(j<u)
			{
				add(c[j]);
				j++;
			}
			printf("%ld\n",a[i]);
		}
		flag=1;
	}
	return 0;
}