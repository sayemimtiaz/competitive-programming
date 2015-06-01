#include<stdio.h>
#include<math.h>
int main()
{
	long long a,b,c,d,i,j,n;
	while(1)
	{
		scanf("%lld",&n);
		if(!n)
			return 0;
		bool f=1;
		for(i=0;;i++)
		{
			a=pow(2,i);
			for(j=0;;j++)
			{
				b=pow(3,j);
				c=a*b;
				if(c>=n)
				{
					if(f)
					{
						f=0;
						d=c;
					}
					else if(d>c)
						d=c;
					break;
				}
			}
			if(!j)
				break;
		}
		printf("%lld\n",d);
	}
	return 0;
}