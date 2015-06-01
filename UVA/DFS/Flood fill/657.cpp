#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long x[4]={0,0,1,-1};
long y[4]={1,-1,0,0};
char grid[1000][1000];
int vis[1000][1000];
long c,r,s1[100000],s2[100000],t1,t2,v[100000];
void push_a(long d)
{
	s1[t1++]=d;
}
void push_b(long d)
{
	s2[t2++]=d;
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
void dfs(long a,long b,char ch)
{
	t1=t2=0;
	long ci,di,i;
	if(ch=='e')
	{
		vis[a][b]=2;
	}
	else
	   vis[a][b]=1;
	push_a(a+1);
	push_b(b+1);
	while(a=pop_a())
	{
		b=pop_b();
		a--;
		b--;
		for(i=0;i<4;i++)
		{
			ci=a+x[i];
			di=b+y[i];
			if(ch=='e'&&ci>=0&&ci<r&&di>=0&&di<c&&!vis[ci][di])
			{
				vis[ci][di]=2;
				push_a(ci+1);
				push_b(di+1);
			}
			else if(ch=='o'&&ci>=0&&ci<r&&di>=0&&di<c&&vis[ci][di]==2&&grid[ci][di]=='X')
			{
				vis[ci][di]=1;
				push_a(ci+1);
				push_b(di+1);
			}
		}
	}
}
int cmp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *x-*y;
}

int main()
{
	long i,j,k,l,m,kas=1;
	while(scanf("%ld %ld",&c,&r)==2&&c&&r)
	{
		memset(vis,0,sizeof(vis));
		for(i=0;i<r;i++)
		{
			getchar();
			for(j=0;j<c;j++)
			{
				scanf("%c",&grid[i][j]);
				if(grid[i][j]=='.')
					vis[i][j]=1;
			}
		}
		memset(v,0,sizeof(v));
		m=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(!vis[i][j])
				{
					dfs(i,j,'e');
					for(l=0;l<r;l++)
					{
						for(k=0;k<c;k++)
						{
							if(vis[l][k]==2&&grid[l][k]=='X')
							{
								v[m]++;
								dfs(l,k,'o');
							}
						}
					}
					m++;
				}
			}
		}
		qsort(v,m,sizeof(long),cmp);
		printf("Throw %ld\n",kas++);
		for(i=0;i<m;i++)
		{
			if(i)
				printf(" ");
			printf("%ld",v[i]);
		}
		printf("\n\n");
		
	}
	return 0;
}