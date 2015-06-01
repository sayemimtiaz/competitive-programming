#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *x-*y;
}
int main()
{
	long a[10000],n,r,i;
	bool flag;
	while(scanf("%ld",&n)==1&&n)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		qsort(a,n,sizeof(long),cmp);
		flag=1;
		for(i=1;i<n;i++)
		{
			if(a[i]-a[i-1]>200)
			{
				flag=0;
				break;
			}
		}
		r=1422-a[n-1];
		if(2*r>200)
			flag=0;
		if(flag)
			printf("POSSIBLE");
		else
			printf("IMPOSSIBLE");
		printf("\n");

	}
	return 0;
}