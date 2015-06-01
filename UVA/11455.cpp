#include<stdio.h>
int main()
{
	double a,b,c,d;
	int i,test;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		if((a+b+c)>=d&&(a+b+d)>=c&&(b+c+d)>=a&&(a+c+d)>=b)
		{
			if(a==b&&b==c&&c==d)
				printf("square");
			else if((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c))
				printf("rectangle");
			else
				printf("quadrangle");
		}
		else
			printf("banana");
		printf("\n");
	}
	return 0;
}
