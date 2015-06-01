#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long  long c[100000];
int cmp(const void *a,const void *b)
{
	long long *x=( long long*)a;
	long long  *y=( long long*)b;
	return *x-*y;
}
int main()
{
    long long j,k,save ,s,r,a,i;
	while(scanf("%lld %lld",&s,&r)==2)
	{
		k=0;
		for(i=1;i<=1000;i++)
		{
			for(j=i+1;j<=1000;j++)
			{
				a=i*i*i+j*j*j;
				if(a>(s+r))
					break;
				if(a>=s&&a<=(s+r))
					c[k++]=a;
			}
		}
		bool f=0,yes=0;
		qsort(c,k,sizeof( long),cmp);
		for(i=1;i<k;i++)
		{
			if(c[i-1]==c[i])
			{
				save=i-1;
				f=1;
			}
			else if(f)
			{
				yes=1;
				printf("%lld\n",c[save]);
				f=0;
			}
		}
		if(f)
		{
			yes=1;
			printf("%lld\n",c[save]);
		}
		
 if(!yes)
	 printf("None\n");
	}
	return 0;
}