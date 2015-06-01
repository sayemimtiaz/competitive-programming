#include<stdio.h>
#include<math.h>
#define INFINITY 1000000000
double d[200][200];
int main()
{
	double max,x[1000],y[1000];
	long kase,i,j,k,n,kas=1;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%lf %lf",&x[i],&y[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					d[i][j]=sqrt(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j])));
					if(d[i][j]>10)
						d[i][j]=INFINITY;
				}
				else
					d[i][j]=INFINITY;
			}
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					 if(d[i][j]>(d[i][k]+d[k][j]))
						d[i][j]=(d[i][k]+d[k][j]);
				}
		max=-1000000;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					if(d[i][j]>max)
						max=d[i][j];
				}
			}
		}
		printf("Case #%ld:\n",kas++);
		if(max>=INFINITY)
			printf("Send Kurdy");
		else
			printf("%0.4lf",max);
		printf("\n\n");

	
	}
	return 0;
}