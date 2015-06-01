#include<stdio.h>
#include<string.h>
#include<iostream.h>
long m,s1[10000],s2[10000],t1,t2;
int x[8]={0,0,-1,1,-1,-1,1,1};
int y[8]={-1,1,0,0,-1,1,-1,1};
char grid[500][500];
bool vis[500][500];
void push_a(long a)
{
	s1[t1]=a;
	t1++;
}
void push_b(long a)
{
	s2[t2]=a;
	t2++;
}
long pop_a()
{
	t1--;
	return s1[t1];
}
long pop_b()
{
	t2--;
	return s2[t2];
}
void dfs(long a,long b)
{
	long c,d,k;
	push_a(0);
	push_b(0);
	push_a(a+1);
	push_b(b+1);
	vis[a][b]=1;
	while(a=pop_a())
	{
		b=pop_b();
		a--;b--;
		c=a;d=b;
		for(k=0;k<8;k++)
		{
			 c=a+x[k];
			 d=b+y[k];
			if(c>=0&&c<m&&d>=0&&d<m&&!vis[c][d]&&grid[c][d]=='1')
			{
		    	push_a(c+1);
				push_b(d+1);
			    vis[c][d]=1;
			  
			}
			 
			  
		}
	}
}
int main()
{

	long i,j,count,k=1;

	while(scanf("%ld",&m)==1)
	{
		memset(vis,0,sizeof(vis));
		t1=t2=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='0')
					vis[i][j]=1;
			}
		}
	
		count=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(vis[i][j]==0)
				{
					count++;
					dfs(i,j);
				
				}
			}
		}
	
		printf("Image number %ld contains %ld war eagles.\n",k++,count);
	}
	return 0;
}