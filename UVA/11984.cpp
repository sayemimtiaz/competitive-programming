#include<stdio.h>
int main()
{
	long kase,kas=1;
	double nf,c,f;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%lf %lf",&c,&f);
		nf=f+(9*c)/5+32;
		printf("Case %ld: %0.2lf\n",kas++,((nf-32)*5)/9);
	}
	return 0;
}