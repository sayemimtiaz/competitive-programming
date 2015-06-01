#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323
int main()
{
	double a,b,c,rad_in,rad_out,a_tri,s;
	while(scanf("%lf %lf %lf",&a,&b,&c)==3)
	{
		s=(a+b+c)/2;
		a_tri=sqrt((s*(s-a)*(s-b)*(s-c)));
		rad_in=a_tri/s;
		rad_out=(a*b*c)/(4*a_tri);
		rad_in=PI*rad_in*rad_in;
		rad_out=(PI*rad_out*rad_out)-a_tri;
		a_tri=a_tri-rad_in;
		printf("%0.4lf %0.4lf %0.4lf\n",rad_out,a_tri,rad_in);
	}
	return 0;
}

