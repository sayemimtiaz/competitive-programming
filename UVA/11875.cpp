#include<stdio.h>
int main()
{
	long a[10000],kase,k,i,n,in;
	scanf("%ld",&kase);
	for(k=1;k<=kase;k++)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		in=n/2;
		printf("Case %ld: %ld\n",k,a[in]);
	}
	return 0;
}