#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,s;
	while(scanf("%lf %lf %lf",&a,&b,&c)==3)
	{
		s=(a+b+c)/2;
		if(!a||!b||!c)
			s=0;
		else
		{
		a=sqrt(s*(s-a)*(s-b)*(s-c));
		s=a/s;
		}
		printf("The radius of the round table is: %0.3lf\n",s);
	}
	return 0;
}
