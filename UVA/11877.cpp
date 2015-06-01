#include<stdio.h>
int main()
{
	long n,ac;
	while(1)
	{
		scanf("%ld",&n);
		if(!n)
			break;
		ac=0;
		while(1)
		{
			if(n==1)
				break;
			else if(n==2)
				n++;
			ac+=(n/3);
			n=(n/3)+(n%3);
		}
		printf("%ld\n",ac);
	}
	return 0;
}