#include<stdio.h>
#include<math.h>
int main()
{
	char str[10000];
	long double t,a,b,c,e,h;
	char c1,c2;
	while(1)
	{
		gets(str);
		if(str[0]=='E')
			break;
		sscanf(str,"%c %Lf %c %Lf",&c1,&a,&c2,&b);
		if((c1=='T'&&c2=='D')||(c1=='D'&&c2=='T'))
		{
			if(c1=='D'&&c2=='T')
			{
				t=a;
				a=b;
				b=t;
			}
			e=6.11*powl(2.718281828,(5417.7530*((1/273.16)-(1/(273.16+b)))));
			h=(0.5555)*(e-10.0);
			c=a+h;
			printf("T %0.1Lf D %0.1Lf H %0.1Lf",a,b,c); 
		}
		else if((c1=='D'&&c2=='H')||(c1=='H'&&c2=='D'))
		{
			if(c1=='D'&&c2=='H')
			{
				t=a;
				a=b;
				b=t;
			}

		    e=6.11*powl(2.718281828,(5417.7530*((1/273.16)-(1/(273.16+b)))));
			h=(0.5555)*(e-10.0);
			c=a-h;
			printf("T %0.1Lf D %0.1Lf H %0.1Lf",c,b,a);
		}
		else
		{
			if(c1=='H'&&c2=='T')
			{
				t=a;
				a=b;
				b=t;
			}
			h=b-a;
			c=(1/(1/273.16 - log((h/0.5555 + 10.0)/6.11)/5417.7530)-273.16);
			printf("T %0.1Lf D %0.1Lf H %0.1Lf",a,c,b);
		}
		printf("\n");
	}
	return 0;
}