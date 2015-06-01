#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
long *x=(long*)a;
   long *y=(long*)b;
 return (*x-*y);
}
int main()
{
	long a[3000];
	long  i,j,k,l,n;
	bool yes;
	while(scanf("%ld",&n)==1&&n)
	{
		yes=0;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		qsort(a,n,sizeof(long),comp);
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<n-2;j++)
			{
				for(k=j+1;k<n-1;k++)
				{
					for(l=k+1;l<n;l++)
					{
						if(l!=i&&j!=i&&k!=i&&a[l]+a[j]+a[k]==a[i])
						{
							printf("%ld\n",a[i]);
							yes=1;
							break;
						}
					}
					if(yes)
						break;
				}
						if(yes)
						break;
			}

					if(yes)
						break;
		}
		if(!yes)
			printf("no solution\n");
	}
	return 0;
}