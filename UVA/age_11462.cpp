#include<stdio.h>
#include<stdlib.h>
long n[2000000];
int comp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *x-*y;
}
int main()
{
	long a,i;
	while(1)
	{
		scanf("%ld",&a);
		if(a==0)
			break;
		for(i=0;i<a;i++)
			scanf("%ld",&n[i]);
		qsort(n,a,sizeof(long int),comp);
		for(i=0;i<a;i++)
		{
			printf("%ld",n[i]);
			if(i<a-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
		