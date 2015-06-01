#include<stdio.h>
int main()
{
	int t;
	int a,j,max,n;
	j=1;
	int i;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(i==0)
				max=a;
			else if(a>max)
				max=a;
		}
		printf("Case %d: %d\n",j,max);
	}
	return 0;
}
