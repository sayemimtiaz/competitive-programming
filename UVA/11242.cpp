#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
	double *x=(double*)a;
	double *y=(double*)b;
	if(*x<*y)
		return -1;
	if(*x>*y)
		return 1;
	return 0;
}
int main()
{
	bool yes;
	double a[6000],b[6000],c[6000],max,d1,d2,d;
	long i,j,k,f,r;
	while(1)
	{
		scanf("%ld",&f);
		if(!f)
			break;
		scanf("%ld",&r);
		for(i=0;i<f;i++)
			scanf("%lf",&a[i]);
		for(i=0;i<r;i++)
			scanf("%lf",&b[i]);
		k=0;
		for(i=0;i<f;i++)
		{
			for(j=0;j<r;j++)
			{
				c[k++]=b[j]/a[i];
			}
		}
		max=-10000000000;
		qsort(c,k,sizeof(double),comp);
		for(i=0;i<k-1;i++)
		{
			d1=c[i];
			d2=c[i+1];
			if(d2>d1)
			{
				yes=0;
				for(j=i-1;j>=0;j--)
					if(c[j]>c[i]&&c[j]<c[i+1])
					{
						yes=1;
						break;
					}
				
				if(!yes)
				{
					d=d2/d1;
					if(max<d)
						max=d;
				}
			}
		}
		printf("%0.2lf\n",max);

	}
	return 0;
}
