#include<stdio.h>
#include<string.h>
long a[100],length,node;
bool vis[100],got;
long grid[100][100];
void check(long next,long how)
{
	long i;
	if(how==length+1)
	{
		got=1;
		printf("(");
		for(i=0;i<length+1;i++)
		{
			if(i)
				printf(",");
			printf("%ld",a[i]);
		}
		printf(")\n");
		return;
	}
	for(i=1;i<=node;i++)
	{
		if(grid[next][i]&&!vis[i])
		{
			vis[i]=1;
			a[how]=i;
			check(i,how+1);
			vis[i]=0;
		}
	}
}
int main()
{
	bool flag=0;
	long foul,i,j;
	while(1)
	{
		if(flag)
			if(scanf("%ld",&foul)!=1)
				break;
		if(scanf("%ld %ld",&node,&length)!=2)
			break;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=node;i++)
			for(j=1;j<=node;j++)
			{
				scanf("%ld",&grid[i][j]);
			}
		a[0]=1;
		got=0;
		vis[1]=1;
		if(flag)
			printf("\n");
		flag=1;
		check(1,1);
		if(!got)
			printf("no walk of length %ld\n",length);
	}
	return 0;
}