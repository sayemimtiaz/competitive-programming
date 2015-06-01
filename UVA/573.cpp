#include<stdio.h>
int main()
{
	double h,u,d,f,Hclimb,a;
	long i;
	while(1)
	{
		scanf("%lf %lf %lf %lf",&h,&u,&d,&f);
		if(h==0)
			break;
		f=(f*u)/(double)100;
		a=0;
		Hclimb=u;
		i=1;
		while(1)
		{
			
			if(Hclimb>h)
			{
				printf("success on day %ld",i);
				break;
			}
			Hclimb-=d;
			if(Hclimb<0)
			{
				printf("failure on day %ld",i);
				break;
			}
			i++;
			a=u-f;
			u=a;
			if(u>=0)
			Hclimb+=u;
		}
		printf("\n");
	}
	return 0;
}
