#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *y-*x;
}
int main()
{
	long kase,n,a[1000],j,i,u,l,d1,d2,M,N,sum,t;
	scanf("%ld",&kase);
	for( i=1;i<=kase;i++)
	{
		scanf("%ld",&n);
		for(j=0;j<n;j++)
			scanf("%ld",&a[j]);
		qsort(a,n,sizeof(long int),comp);
		sum=a[0]-a[n-1];
		u=a[0];
		l=a[n-1];
		M=1;
		N=n-2;
		for(j=2;j<n;j++)
		{
			d1=(abs(u-a[M]))>(abs(a[M]-l))?abs(u-a[M]):abs(a[M]-l);
			d2=(abs(u-a[N]))>(abs(a[N]-l))?abs(u-a[N]):abs(a[N]-l);
			sum+=(d1>d2)?d1:d2;
		    t=(d1>d2)?((abs(u-a[M])>abs(a[M]-l))?1:2):((abs(u-a[N])>abs(a[N]-l))?3:4);
			if(t==1)
				u=a[M];
			else if(t==2)
				l=a[M];
			else if(t==3)
				u=a[N];
			else
				l=a[N];
			(d1>d2)?M++:N--;
		}
		printf("Case %ld: %ld\n",i,sum);
	}
	return 0;
}
