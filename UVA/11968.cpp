#include<cstdio>
using namespace std;
#define eps 0.000000001
int main()
{
	int i,j,kas=1,kase,n,m,k;
	double a[2000],A,sum,s,d;
	scanf("%d",&kase);
	while(kase--)
	{
		scanf("%d %d %d",&n,&m,&k);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			sum+=a[i];
		}
		sum/=(double)n;
		printf("Case #%d:",kas++);
		A=a[0];s=sum-a[0];
		if(s<-eps)
			s=-s;
		for(i=1;i<m;i++)
		{
		    d=sum-a[i];
		   if(d<-eps)
			d=-d;
			if((s-d>eps)||(s-d>-eps&&s-d<eps&&A>a[i]))
			{
				s=d;
				A=a[i];
			}
			
		}
		printf(" %0.lf",A);
		A=a[i];s=sum-a[i];
		if(s<-eps)
			s=-s;
		for(j=i+1;j<(m+k);j++)
		{
		    d=sum-a[j];
		   if(d<-eps)
			d=-d;
			if((s-d>eps)||(s-d>-eps&&s-d<eps&&A>a[i]))
			{
				s=d;
				A=a[j];
			}
		}
		printf(" %0.lf",A);
		printf("\n");

	}
	return 0;
}
