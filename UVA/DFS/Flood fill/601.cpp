#include<stdio.h>
#include<string.h>
#include<iostream.h>
long fu,n,s1[10000],s2[10000],t1,t2,fill,fo;
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
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
		for(k=0;k<4;k++)
		{
			 c=a+x[k];
			  d=b+y[k];
			if(c>=0&&c<n&&d>=0&&d<n&&!vis[c][d]&&grid[c][d]==ch)
			{
		    	push_a(c+1);
				push_b(d+1);
			    vis[c][d]=fill;
				if(fu==1&&fo&&d==n-1)
					return 1;
				else if(fu==2&&fo&&c==n-1)
					return 1;

			}
		}
	}
	return 0;
}
int main()
{

	long i,j,c,d,k;
	int f1,f2,f3;
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
		if(n==1)
		{
			if(grid[0][0]=='W')
					printf("White has a winning path.");
			else if(grid[0][0]=='B')
					printf("Black has a winning path.");
			else
						printf("White can win in one move.");

		}
		else
		{
			f1=0;
		for(i=0;i<n;i++)
		{
			fu=1;
			fo=1;
			fill=1;
			if(!vis[i][0]&&grid[i][0]=='W')
				f1=dfs(i,0,'W');
			if(f1)
				break;
		}
		if(f1)
			printf("White has a winning path.");
		else
		{
			for(i=0;i<n;i++)
			{
			  fo=0;
			  fill=2;
			  if(!vis[i][n-1]&&grid[i][n-1]=='W')
			  {
				dfs(i,n-1,'W');
			  }
			}
			f2=f3=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					f2=f3=0;
					if(grid[i][j]=='U')
					{
						if(j==n-1&&vis[i][j-1]==1)
						{
							f1=1;
							break;
						}
						for(k=0;k<4;k++)
						{
			               c=i+x[k];
			               d=j+y[k];
						   if(c>=0&&c<n&&d>=0&&d<n)
						   {

							   if(vis[c][d]==1)
							   {
								   f2=1;
							   }
							   else if(vis[c][d]==2)
							   {
								   f3=1;
							   }
						   }
						}
						if(f2&&f3)
						{
							f1=1;
							break;
						}
					}
				}
				if(f1)
					break;
			}
		if(f1)
			printf("White can win in one move.");
		}
		if(!f1)
		{
		for(i=0;i<n;i++)
		{
			fu=2;
			fo=1;
			fill=3;
			if(!vis[0][i]&&grid[0][i]=='B')
				f1=dfs(0,i,'B');
			if(f1)
				break;
		}
		
		if(f1)
			printf("Black has a winning path.");
		else
		{
			for(i=0;i<n;i++)
			{
			  fo=0;
			  fill=4;
			  if(!vis[n-1][i]&&grid[n-1][i]=='B')
				dfs(n-1,i,'B');
			}
			f2=f3=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					f2=f3=0;
					if(grid[i][j]=='U')
					{
						if(i==n-1&&vis[i-1][j]==3)
						{
							f1=1;
							break;
						}
						for(k=0;k<4;k++)
						{
			               c=i+x[k];
			               d=j+y[k];
						   if(c>=0&&c<n&&d>=0&&d<n)
						   {
							   if(vis[c][d]==3)
								   f2=1;
							   else if(vis[c][d]==4)
								   f3=1;
						   }
						}
						if(f2&&f3)
						{
							f1=1;
							break;
						}
					}
				}
				if(f1)
					break;
			}
			if(f1)
				printf("Black can win in one move.");
		}
		}
		if(!f1)
			printf("There is no winning path.");
		}

		printf("\n");
	}
	return 0;
}