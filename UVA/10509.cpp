#include<stdio.h>
#include<math.h>
int main()
{
	double n,a,b;
	while(1)
	{
		scanf("%lf",&n);
		if(n==0)
			break;
		b=pow(n,0.333333333);
		a=b;
		b=ceil(b);
		a=floor(a);
		if(pow(b,3)!=n)
			b=a+(n-(pow(a,3)))/(3*(pow(a,2)));
		printf("%0.4lf\n",b);
	}
	return 0;
}