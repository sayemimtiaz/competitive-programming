#include<stdio.h>
#include<math.h>
long n;
void master(long in,long ho,long min)
{
	long b,dig,d,c;
	double a;
		b=(n-in);
			a=b/(double)ho;
			a=ceil(a);
			dig=min+a;
			a=ho*a;
			b=a-b;
			c=0;
			while(dig)
			{
				d=dig%10;
				if(c==b)
				{
					printf("%ld\n",d);
					break;
				}
				c++;
				dig/=10;
			}
}
int main()
{
	while(scanf("%ld",&n)==1)
	{
		if(n<=9)
		{
			printf("%ld\n",n);
		}
		else if(n<=189)
		{
			master(9,2,9);

		}
		else if(n<=2889)
		{
				master(189,3,99);
		}
		else if(n<=38889)
		{
				master(2889,4,999);
		}
		else if(n<=488889)
		{
				master(38889,5,9999);
		}
		else if(n<=5888889)
		{
				master(488889,6,99999);
		}
		else if(n<=68888889)
		{
				master(5888889,7,999999);
		}
		else if(n<=788888889)
		{
				master(68888889,8,9999999);
		}
		else
		{
				master(788888889,9,99999999);
		}
	}
	return 0;
}