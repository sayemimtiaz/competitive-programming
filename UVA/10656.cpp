#include<stdio.h>
int main()
{
	int n,a[10000],i;
	while(1)
	{
		scanf("%ld",&n);
		if(n==0)
			break;
		bool yes=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
		}
		bool f=0;
		for(i=0;i<n;i++)
		{
			if(a[i])
			{
				yes=1;
				if(f)
					printf(" ");
				f=1;
				printf("%ld",a[i]);
			}
		}
		if(!yes)
			printf("0");
		printf("\n");
	}
	return 0;
}