#include<stdio.h>
#include<stdlib.h>
long a[100000];
int comp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *y-*x;
}
int main()
{
	long kase,i,sum,n;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		sum=0;
		qsort(a,n,sizeof(long int),comp);
		for(i=0;i<n;i++)
		{
			if((i+1)%3==0)
				sum+=a[i];
		}
		printf("%ld\n",sum);
	}
	return 0;
}