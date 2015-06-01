#include<stdio.h>
long a[1000000];
bool f[1000000];
int main()
{
	long prev,save,kase,q,n,u,l,i,d;
	bool got;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		scanf("%ld",&q);
		while(q--)
		{
			scanf("%ld %ld",&l,&u);
			for(i=0;i<=10000;i++)
				f[i]=0;
			got=0;
			for(i=l-1;i<u;i++)
			{
				if(!f[a[i]])
					f[a[i]]=1;
				else
				{
					got=1;
					break;
				}
			}
			if(got||l==u)
			{
				printf("0\n");
				continue;
			}
			got=0;
			prev=1000000000;
			for(i=1;i<=10000;i++)
			{
				if(f[i])
				{
					if(!got)
					{
						got=1;
						save=i;
					}
					else
					{
						d=i-save;
						if(d<prev)
							prev=d;
						save=i;
					}
				}
			}
			printf("%ld\n",prev);

		}
	}
	return 0;
}