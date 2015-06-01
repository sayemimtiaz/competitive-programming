#include<stdio.h>
#include<math.h>
bool vis[10];
long n,a[10],list[10];
long double grid[10][10],save;
void route(long r,long double length,long how)
{
	long i;
	if(length>=save)
		return;
	if(how>n)
	{
		if(length<save)
		{
			save=length;
			list[1]=a[1];
			for(i=2;i<how;i++)
				list[i]=a[i];
		}
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(i!=r&&!vis[i])
		{
			a[how]=i;
			vis[i]=1;
			route(i,length+grid[r][i],how+1);
		    vis[i]=0;
		}
	}
}
int main()
{
	long double x[10],y[10],d;
	long kas=1,i,j;
	while(scanf("%ld",&n)==1&&n)
	{
		for(i=1;i<=n;i++)
			scanf("%Lf %Lf",&x[i],&y[i]);
		save=2000000000;
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			for(j=i+1;j<=n;j++)
			{
				d=sqrtl((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				grid[i][j]=grid[j][i]=d+16;
			}
		}
		for(i=1;i<=n;i++)
		{
		vis[i]=1;
		a[1]=i;
		route(i,0,2);
		vis[i]=0;
		}
		printf("**********************************************************\n");
		printf("Network #%ld\n",kas++);
		for(i=1;i<n;i++)
			printf("Cable requirement to connect (%0.Lf,%0.Lf) to (%0.Lf,%0.Lf) is %0.2Lf feet.\n",x[list[i]],y[list[i]],x[list[i+1]],y[list[i+1]],grid[list[i]][list[i+1]]);
		printf("Number of feet of cable required is %0.2Lf.\n",save);
	}
	return 0;
}