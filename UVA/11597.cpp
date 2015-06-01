#include<stdio.h>
int main()
{
	long i, n;
	i=1;
	while(scanf("%ld",&n)==1)
	{
		if(!n)
			break;
		printf("Case %ld: %ld\n",i,(n/2));
	i++;
	}
	return 0;

}