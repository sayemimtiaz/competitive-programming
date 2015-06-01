#include<stdio.h>
#include<string.h>
bool test[100000];
int main()
{
	long i,j,n,a[1000],sum,kase=1;
	bool flag;
	while(scanf("%ld",&n)==1)
	{
		flag=1;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			if(i==0)
			{
				if(a[i]<1)
				flag=0;
			}
			else if(a[i]<a[i-1])
				flag=0;
		}
		if(flag)
		{
			memset(test,0,sizeof(test));
			for(i=0;i<n;i++)
			{
				for(j=i;j<n;j++)
				{
					sum=a[i]+a[j];
					if(test[sum])
					{
						flag=0;
						break;
					}
					test[sum]=1;
				}
				if(!flag)
					break;
			}
		}
		printf("Case #%ld: ",kase++);
		if(flag)
			printf("It is a B2-Sequence.");
		else
				printf("It is not a B2-Sequence.");
		printf("\n\n");
	}
	return 0;
}