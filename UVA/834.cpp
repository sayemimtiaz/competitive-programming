#include<stdio.h>
int main()
{
	long long a,b,c;
	bool h=1;
	while(scanf("%lld %lld",&a,&b)==2)
	{
		h=1;
		printf("[");
		while(b)
		{
			c=a/b;
			if(h)
				printf("%lld;",c);
			else
				printf("%lld",c);
			c=a;
			a=b;
			b=c%b;
			if(!b)
			break;
			if(!h)
				printf(",");
			h=0;
		}
		printf("]\n");

	}
	return 0;
}