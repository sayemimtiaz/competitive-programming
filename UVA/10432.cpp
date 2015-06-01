#include<stdio.h>
#include<math.h>
#define pi 4*acos(0.0)
int main()
{
	long double r ,n;
	while(scanf("%Lf %Lf",&r,&n)==2)
	{
		printf("%0.3Lf\n",(n*0.5*r*r*sin(pi/n)));
	}
	return 0;
}