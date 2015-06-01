#include<stdio.h>
char grid[10][10];
bool vis[10][10],p[10][10];
int n,save;
bool isthr(int i,int j)
{
	int k;
	for(k=j+1;k<n;k++)
		if(grid[i][k]=='X')
			break;
		else if(p[i][k])
			return false;
	for(k=j-1;k>=0;k--)
		if(grid[i][k]=='X')
			break;
		else if(p[i][k])
			return false;
	for(k=i+1;k<n;k++)
		if(grid[k][j]=='X')
			break;
		else if(p[k][j])
			return false;
	for(k=i-1;k>=0;k--)
		if(grid[k][j]=='X')
			break;
		else if(p[k][j])
			return false;
	return true;
}
void mark(int i,int j,bool flag)
{
	int k;
	vis[i][j]=flag;
	for(k=j;k<n;k++)
		if(grid[i][k]=='X')
			break;
		else
		{
			if(!flag&&isthr(i,k))
			     vis[i][k]=flag;
			if(flag)
				vis[i][k]=flag;
		}
	for(k=j;k>=0;k--)
		if(grid[i][k]=='X')
			break;
		else
		{
				if(!flag&&isthr(i,k))
			vis[i][k]=flag;
			if(flag)
				vis[i][k]=flag;
		}
	for(k=i;k<n;k++)
		if(grid[k][j]=='X')
			break;
		else
		{
		if(!flag&&isthr(k,j))
			vis[k][j]=flag;
			if(flag)
				vis[k][j]=flag;
		}
	for(k=i;k>=0;k--)
		if(grid[k][j]=='X')
			break;
		else
		{
					if(!flag&&isthr(k,j))
			vis[k][j]=flag;
			if(flag)
				vis[k][j]=flag;
		}

}
void place(int i,int j,int how)
{
	if(how>save)
	{
		save=how;

	}
	int k,m;
	for(k=i;k<n;k++)
		for(m=0;m<n;m++)
			if(!vis[k][m])
			{
				mark(k,m,1);
				p[k][m]=1;
			
				place(k,m,how+1);
					p[k][m]=0;
				mark(k,m,0);
			
			
			}
}
int main()
{
	int i,j;
	while(scanf("%d",&n)==1&&n)
	{
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<n;j++)
			{
				scanf("%c",&grid[i][j]);
				if(grid[i][j]=='X')
					vis[i][j]=1;
				else
					vis[i][j]=0;
				p[i][j]=0;
			}
		}
		save=-100000000;
		place(0,0,0);
		printf("%d\n",save);
	}
	return 0;
}