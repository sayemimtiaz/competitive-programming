#include<stdio.h>
#include<math.h>
#define INFINITY 100000000
double d[200][200];
double w[200][200];

int main()
{
	long a[10000],b[10000];
	double dis;
	long n,i,j,k,h=1;
	while(1)
	{
		scanf("%ld",&n);
		if(!n)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%ld %ld",&a[i],&b[i]);
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				w[i][j]=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				dis=sqrt(((a[i]-a[j])*(a[i]-a[j]))+((b[i]-b[j])*(b[i]-b[j])));
				w[i][j]=w[j][i]=dis;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					d[i][j]=0;
				else if(w[i][j])
				d[i][j]=w[i][j];
				else
				d[i][j]=INFINITY;
			}
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					dis=(d[i][k]>d[k][j])?d[i][k]:d[k][j];
					d[i][j]=(d[i][j]<dis)?d[i][j]:dis;
				}
			printf("Scenario #%ld\n",h++);
			printf("Frog Distance = %0.3lf\n\n",d[0][1]);
	}
	return 0;
}