#include<stdio.h>
long g[100000],y[100000],r[100000];
long double l[100000];
int main()
{
	bool flag,yes,track;
	long i,j,n,post,save,kas=1,min;
	long double pass,r1,r2;
	while(scanf("%ld",&n)==1&&n!=-1)
	{
		for(i=0;i<n;i++)
			scanf("%Lf %ld %ld %ld",&l[i],&g[i],&y[i],&r[i]);
		track=yes=1;
		printf("Case %ld:",kas++);
		for(i=30;i<=60;i++)
		{
			post=0;
			for(j=0;j<n;j++)
			{
				r1=(i*(g[j]+y[j]))/(long double)3600;
				r2=(i*r[j])/(long double)3600;
				flag=1;
				pass=min=0;
			    while(1)
				{
					if(flag)
					{
						min+=(g[j]+y[j]);
					   pass+=r1;
					}
					else
					{
						min+=r[j];
						pass+=r2;
					}
					if(flag&&pass>l[j])
					{
						post++;
						break;
					}
					else if(!flag&&pass-l[j]>1e-4)
					{
						break;
					}
					if(flag)
					{
						flag=0;
					}
					else
					{
						flag=1;
					}
				
				
				}
			}
			if(post==n)
			{
				if(yes)
				{
					save=i;
					yes=0;
					printf(" %ld",i);
				}
				else if(i-save==1)
				{
					track=0;
					save=i;
				}
				else
				{
					if(!track)
					{
						printf("-%ld",save);
						track=1;
					}
					printf(", %ld",i);
					save=i;
				}

			}
		}
		if(yes)
			printf(" No acceptable speeds.");
		else if(!track)
			printf("-%ld",save);
		printf("\n");
	}
	return 0;
}