#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,s;
	while(scanf("%lf %lf %lf",&a,&b,&c)==3)
	{
		s=(a+b+c)/2;
		s=sqrt(s*(s-a)*(s-b)*(s-c));
		if(s>0)
			printf("%0.3lf",((s*4)/3));
		else
			printf("-1.000");
		printf("\n");
	}
	return 0;
}