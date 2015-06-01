#include<stdio.h>
#include<math.h>
#include<string.h>
#define size 1000000
long x[size],y[size],z[size];
void precal()
{
	long i,j,k,b, m=50000;
	m=sqrt(m);
		for(i=0;i<=m;i++)
		{
			for(j=i;j<=m;j++)
			{
				for(k=j;k<=m;k++)
				{
					b=i*i+j*j+k*k;
					if(b<=50000)
					{
						if(!x[b]&&!y[b]&&!z[b])
						{
						x[b]=i;
						y[b]=j;
						z[b]=k;
						}
					}
					if(b>=50000)
						break;
				}
			}
		}
}
int main()
{
	long n,b;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(z,0,sizeof(z));
	precal();
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld",&b);
		if(!x[b]&&!y[b]&&!z[b])
					printf("-1\n");
		else
		printf("%ld %ld %ld\n",x[b],y[b],z[b]);

	}
	return 0;
}