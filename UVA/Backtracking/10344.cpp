#include<stdio.h>
#include<memory.h>
long  a[1000],b[1000],cnt=0;
bool flag,vis[1000];
void check(long sum,long how)
{
	if(how==5)
	{
		if(sum==23)
			flag=1;
		return;
	}
	check(sum+b[how],how+1);
	check(sum-b[how],how+1);
	check(sum*b[how],how+1);
}
void permute(long how)
{
	if(how==5)
	{
		check(b[0],1);
		return;
	}
	long  i;
	for(i=0;i<5;i++)
		if(!vis[i])
		{
			vis[i]=1;
			b[how]=a[i];
			permute(how+1);
			vis[i]=0;
		}
}
int main()
{
	long i;
	while(1)
	{
		flag=0;
		for(i=0;i<5;i++)
		{
			scanf("%ld",&a[i]);
			vis[i]=0;
		}
		if(!a[0]&&!a[1]&&!a[2]&&!a[3]&&!a[4])
			break;
		for(i=0;i<5;i++)
		{
			b[0]=a[i];
			vis[i]=1;
			permute(1);
			vis[i]=0;
		}
		if(!flag)
			printf("Impossible\n");
		else
			printf("Possible\n");
	}
	return 0;
}