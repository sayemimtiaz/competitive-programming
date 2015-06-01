#include<stdio.h>
long s[100],S,T;
bool g[101][101];
bool gcd(long a,long b)
{
	long t;
	while(b)
	{
		t=b;
		b=a%b;
		a=t;
	}
	if(a==1)
		return 1;
	return 0;
}
void check(long how,long sum)
{
	long i,j;
	for(i=1;i<how-2;i++)
		for(j=i+1;j<how;j++)
			if(!g[s[i]][s[j]])
					return;
	if(how==T+1)
	 {
		if(sum==S)
		{
			printf("%ld",s[1]);
			for(i=2;i<how;i++)
				printf(" %ld",s[i]);
			printf("\n");
		}
		return;
	}
	for(i=1;i<=S;i++)
	{
		if(i>=s[how-1]&&(i+sum)<=S)
		{
			if(g[s[how-1]][i])
			{
			s[how]=i;
			check(how+1,sum+i);
			}
		}
	}
}
int main()
{
	s[0]=0;
	g[1][1]=1;
	long i,j;
	for(i=1;i<=100;i++)
		g[0][i]=1;
	for(i=2;i<=100;i++)
		for(j=i+1;j<=100;j++)
			g[i][j]=gcd(i,j);
	for(i=2;i<=100;i++)
		g[i][i]=0;
    for(i=2;i<=100;i++)
			g[1][i]=1;
	long kase,kas=1;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld %ld",&S,&T);
		printf("Case %ld:\n",kas++);
		check(1,0);
	}
	return 0;
}