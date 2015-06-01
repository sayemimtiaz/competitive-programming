#include<stdio.h>
long a[1000000];
int main()
{
	long kase,max,m,l,n,i,b;
	scanf("%ld",&kase);
	while(kase--)
	{
		max=m=0;
		scanf("%ld %ld",&l,&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			b=l-a[i];
			b=(b>a[i])?a[i]:b;
			if(b>max)
			{
				max=b;
			}
			b=l-a[i];
			b=(b<a[i])?a[i]:b;
			if(b>m)
				m=b;

		}
		printf("%ld %ld\n",max,m);
	}
	return 0;
}