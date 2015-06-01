#include<stdio.h>
int main()
{
	long double max,p;
	long  n,k=0,i,a[1000],j;
	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		max=0;
		for(i=0;i<n;i++)
		{
			p=a[i];
				if(p>max)
					max=p;
			for(j=i+1;j<n;j++)
			{
				p*=a[j];
				if(p>max)
					max=p;
			}
		}
		k++;
		printf("Case #%ld: The maximum product is %0.Lf.",k,max);
		printf("\n\n");
	}
	return 0;
}
