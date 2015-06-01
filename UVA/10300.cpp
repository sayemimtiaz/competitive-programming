#include<stdio.h>
int main()
{
	long test,n,a,b,c,tot;
	scanf("%ld",&test);
	while(test--)
	{
		tot=0;
		scanf("%ld",&n);
		while(n--)
		{
			scanf("%ld %ld %ld",&a,&b,&c);
			tot+=(a*c);
		}
		printf("%ld\n",tot);
	}
	return 0;
}