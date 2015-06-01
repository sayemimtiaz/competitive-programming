#include<stdio.h>
long long a[1000000],c[1000000];
int main()
{
	long long i,j,k,q,n,e,m,b,d,kas=1;
	while(scanf("%lld",&n)==1&&n)
	{
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&c[i]);
		printf("Case %lld:\n",kas++);
		for(i=0;i<q;i++)
		{
			m=100000000000;
			for(j=0;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					if(a[j]!=a[k])
					{
					b=a[j]+a[k];
					d=c[i]-b;
					if(d<0)
						d=-d;
					if(d<m)
					{
						m=d;
						e=b;
					}
					}
				}
			}
			printf("Closest sum to %lld is %lld.\n",c[i],e);
		}
	}
	return 0;
}