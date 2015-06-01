#include<stdio.h>
bool grid[100][100],vis[100],q[100][100];
long n,cnt;
long a[1000];
void route(long r,long how)
{
	if(!q[r][n])
		return;
	long i;
	if(r==n)
	{
		cnt++;
		for(i=1;i<how;i++)
		{
			printf("%ld",a[i]);
			if(i<how-1)
				printf(" ");
		}
		printf("\n");
		return;
	}
	for(i=1;i<21;i++)
	{
		if(grid[r][i]&&!vis[i])
		{
			vis[i]=1;
			a[how]=i;
			route(i,how+1);
		    vis[i]=0;
		}
	}
}
int main()
{
	long p,b,kas=1,i,j,w;
	while(scanf("%ld",&n)==1)
	{
		for(p=0;p<=21;p++)
		{
			vis[p]=0;
			for(b=0;b<=21;b++)
				grid[p][b]=0;
		}
		cnt=0;
		while(scanf("%ld %ld",&p,&b)==2)
		{
			if(!p&&!b)
				break;
		   grid[p][b]=grid[b][p]=1;
		}
		for(i=0;i<22;i++)
		{
		for(j=0;j<22;j++)
		{
			if(grid[i][j]==0)
				q[i][j]=0;
			else
				q[i][j]=1;
		}
	}
	for(i=0;i<22;i++)
		for(j=0;j<22;j++)
			for(w=0;w<22;w++)
						q[j][w]=q[j][w]|q[j][i]&q[i][w];
		a[1]=1;
		vis[1]=1;
		printf("CASE %ld:\n",kas++);
		route(1,2);
		printf("There are %ld routes from the firestation to streetcorner %ld.\n",cnt,n);
	}
	return 0;
}