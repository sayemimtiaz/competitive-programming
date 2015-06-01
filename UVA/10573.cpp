#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	double a,b,r;
	char ch;
	while(n--)
	{
		scanf("%lf",&a);
		ch=getchar();
		if(ch=='\n')
		{
			r=a/2;
			b=r/2;
			a=(3.14159265358979*(b*b));
				r=(3.14159265358979*(r*r));
			r=r-(a+a);
		}
		else
		{
			scanf("%lf",&b);
			r=2*a+2*b;
			r=r/2;
			a=(3.14159265358979*(a*a));
			b=(3.14159265358979*(b*b));
			r=(3.14159265358979*(r*r));
			r=r-(a+b);
		
		}
			printf("%0.4lf",r);
		printf("\n");
	}
	return 0;
}
