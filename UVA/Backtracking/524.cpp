#include<stdio.h>
#include<string.h>
bool vis[1000];
long n,a[100];
bool prime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0};
void check(long next)
{
	long i;
	if(next==n)
	{
		if(prime[a[next-1]+a[0]])
		{
	   for(i=0;i<next;i++)
	   {
		   if(i)
			   printf(" ");
			printf("%ld",a[i]);
	   }
	   printf("\n");
		}
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i]&&prime[a[next-1]+i])
		{
			vis[i]=1;
			a[next]=i;
			check(next+1);
			vis[i]=0;
		}
	}
}
int main()
{
	bool flag=0;
	long kas=1;
	while(scanf("%ld",&n)==1)
	{
		memset(vis,0,sizeof(vis));
		a[0]=1;
		vis[1]=1;
		if(flag)
			printf("\n");
		flag=1;
		printf("Case %ld:\n",kas++);
		check(1);
	}
	return 0;
}