#include<stdio.h>
#include<string.h>
bool vis[100];
long n,a[100],b[100],c[100],save,hw,amnt;
void check(long sum,long next,long how)
{
	long i;
	if(sum>n)
		return;
	if(save<sum)
	{
	   for(i=0;i<how;i++)
		   c[i]=a[i];
	   save=sum;
	   hw=how;
	 }
	for(i=next;i<amnt;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[how]=b[i];
			check(sum+a[how],i+1,how+1);
			vis[i]=0;
		}
	}
}
int main()
{
	bool flag=0;
	long i;
	while(scanf("%ld",&n)==1)
	{
		scanf("%ld",&amnt);
		for(i=0;i<amnt;i++)
			scanf("%ld",&b[i]);
		memset(vis,0,sizeof(vis));
		save=-100000000;
		for(i=0;i<amnt;i++)
		{
		a[0]=b[i];
		vis[i]=1;
		check(a[0],1,1);
		vis[i]=0;
		}
		for(i=0;i<hw;i++)
		{
			printf("%ld ",c[i]);
		}
		printf("sum:%ld\n",save);
	}
	return 0;
}