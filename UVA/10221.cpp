#include<stdio.h>
#include<math.h>
# define PI 3.1415926535897932384626433832795 
int main()
{
	long double s,d,c;
	char ch;
	char str[1000];
	while(gets(str))
	{
		sscanf(str,"%Lf %Lf %c",&s,&d,&ch);
		if(ch=='m')
			d=d/60;
		if(d>180)
			d=360-d;
		d=(PI*d)/180;
		printf("%0.6Lf ",((6440+s)*d));
		c=sqrtl(2*(6440+s)*(6440+s)-2*(6440+s)*(6440+s)*cosl(d));
		printf("%0.6Lf\n",c);
	}
	return 0;
}