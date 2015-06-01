#include<stdio.h>
int main()
{
	long kase;
	double a,b,c,s;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		s=(a+b+c)/(double)2;
		if(s>0&&(s-a)>0&&(s-b)>0&&(s-c)>0)
			printf("OK\n");
		else
			printf("Wrong!!\n");
	}
	return 0;
}
