#include<stdio.h>
#include<math.h>
int main()
{
	long double y;
	long test;
	scanf("%ld",&test);
	int i=0;
	while(test--)
	{
		scanf("%Lf",&y);
		if(i!=0)
			printf("\n");
		i=1;
		printf("%0.Lf\n",sqrtl(y));
	}
	return 0;
}