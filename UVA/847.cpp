#include<stdio.h>
int main()
{
	long long n,i,a;

	while(scanf("%lld",&n)==1)
	{
			i=1;
			a=1;
		while(1)
		{
			if(i==1)
			{
				a=a*9;
				if(a>=n)
					break;
				i=2;
			}
			if(i==2)
			{
				a=a*2;
				if(a>=n)
					break;
				i=1;
			}
		}
		if(i==1)
			printf("Stan wins.");
			else
				printf("Ollie wins.");
			printf("\n");
	}
	return 0;
}