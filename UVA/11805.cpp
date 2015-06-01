#include<stdio.h>
int main()
{
	int n,k,p,t,i,j,a;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&n,&k,&p);
		a=k;
		for(j=1;j<=p;j++)
		{
			a++;
			if(a>n)
				a=1;
		}
		printf("Case %d: %d\n",i,a);
	}
	return 0;
}


