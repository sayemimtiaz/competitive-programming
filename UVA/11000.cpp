#include<stdio.h>
int main()
{
	long n,a,b,c,d,e,i;
	while(1)
	{
		scanf("%ld",&n);
		if(n==-1)
			break;
		a=1;
		b=0;
		i=0;
		while(1)
		{
			c=a+b;
			a=b;
			b=c;
			i++;
			if(i==(n+2))
				d=c;
			if(i==(n+3))
			{
				e=c;
				break;
			}
		}
		printf("%ld %ld\n",d-1,e-1);
	}
	return 0;
}
