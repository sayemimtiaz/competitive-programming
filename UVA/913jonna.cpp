#include<stdio.h>
#include<math.h>
int main()
{
	long double n,a;
	while(scanf("%Lf",&n)==1)
	{
		a=n*ceil(n/2)+floor(n/2);
		a=(a+(a-2)+(a-4));
		printf("%0.Lf\n",a);
	}
	return 0;
}