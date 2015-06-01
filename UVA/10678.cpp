#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)
int main()
{
	long double d,l,a;
	long test;
	scanf("%ld",&test);
	while(test--)
	{
		scanf("%Lf %Lf",&d,&l);
		a=l/2;
		d=((l/2)*(l/2))-((d/2)*(d/2));
		d=sqrtl(d);
		d=d*PI*a;
		printf("%0.3Lf\n",d);
	}
	return 0;
}