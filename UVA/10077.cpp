#include<stdio.h>
long gcd(long a,long b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
long lcm(long a,long b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	long a,b,c,d,x,y,e,f;
	while(1)
	{
		long m[4]={0,1,1,0};
		scanf("%ld %ld",&a,&b);
		if(a==1&&b==1)
			break;
		while(1)
		{
			x=m[0]+m[2];
			y=m[1]+m[3];
			c=lcm(b,y);
			f=c/y;
			d=x*f;
			f=c/b;
			e=a*f;
			if(d==e)
				break;
			if(d>e)
			{
				printf("L");
				m[2]=x;m[3]=y;
			}
			else
			{
				printf("R");
				m[0]=x;m[1]=y;
			}

		}
		printf("\n");
	}
	return 0;
}