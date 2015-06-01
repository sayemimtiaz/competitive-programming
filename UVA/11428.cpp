#include<stdio.h>]
#define size 100000
long x[size],y[size];
void precal()
{
	long i,j,a;
	for(i=1;;i++)
	{
		for(j=i+1;;j++)
		{
			a=j*j*j-i*i*i;
			if(a<=10000)
			{
				if(!x[a]&&!y[a])
				{
				x[a]=j;
				y[a]=i;
				}
			}
			if(a>=10000)
				break;
		}
		if(a>=10000&&j==i+1)
			break;
	}
}
int main()
{
	long n;
	precal();
	while(scanf("%ld",&n)==1&&n)
	{
		if(!x[n]&&!y[n])
			printf("No solution\n");
		else
		    printf("%ld %ld\n",x[n],y[n]);
	}
	return 0;
}