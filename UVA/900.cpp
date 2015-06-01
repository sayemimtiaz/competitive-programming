#include<iostream.h>
int main()
{
	long long n,i,a,b,c;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		a=0;
		b=1;
		i=1;
		while(1)
		{
			c=a+b;
			a=b;
			b=c;
			if(i==n)
				break;
			i++;
		}
		printf("%lld\n",c);
	}
	return 0;
}
			