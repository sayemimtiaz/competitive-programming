#include<stdio.h>
#include<math.h>
int main()
{
	long double n,p;
	while(scanf("%Lf %Lf",&n,&p)==2)
	{
		p=(logl(p)/n);
		p=exp(p);
		printf("%0.Lf\n",p);
	}
	return 0;
}