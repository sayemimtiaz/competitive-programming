#include<stdio.h>
#include<string.h>
#include<iostream.h>
long fu,n,s1[10000],s2[10000],t1,t2,fill;
int x[6]={-1,0,1,-1,0,1};
int y[6]={-1,-1,0,0,1,1};
char grid[500][500];
long vis[500][500];
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
int dfs(long a,long b,char ch)
{
	t1=t2=0;
	long c,d,k;
	push_a(0);
	push_b(0);
	push_a(a+1);
	push_b(b+1);
	vis[a][b]=fill;
	while(a=pop_a())
	{
		b=pop_b();
		a--;b--;
		c=a;d=b;
		for(k=0;k<6;k++)
		{
			 c=a+x[k];
			  d=b+y[k];
			if(c>=0&&c<n&&d>=0&&d<n&&!vis[c][d]&&grid[c][d]==ch)
			{
		    	push_a(c+1);
				push_b(d+1);
			    vis[c][d]=fill;
				if(fu==1&&d==n-1)
					return 1;
				else if(fu==2&&c==n-1)
					return 1;

			}
		}
	}
	return 0;
}
int main()
{

	long i,j,kas=1;
	long f1;
	while(1)
	{
		scanf("%ld",&n);
		if(!n)
			break;
		memset(vis,0,sizeof(vis));
		t1=t2=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>grid[i][j];
			}
		}
		f1=0;
		for(i=0;i<n;i++)
		{
			fu=1;
			fill=1;
			if(!vis[i][0]&&grid[i][0]=='w')
				f1=dfs(i,0,'w');
			if(f1)
				break;
		}
		if(f1)
			printf("%ld W\n",kas);
		else
		{
		for(i=0;i<n;i++)
		{
			fu=2;
			fill=3;
			if(!vis[0][i]&&grid[0][i]=='b')
				f1=dfs(0,i,'b');
			if(f1)
				break;
		}
		if(f1)
			printf("%ld B\n",kas);
		}
		kas++;
	}
	return 0;
}