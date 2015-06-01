#include<stdio.h>
#include<string.h>
#include<iostream.h>
long m,n,s1[10000],s2[10000],t1,t2,val[1000000],how;
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
char grid[1000][1000],ch[10000],store[1000000];
bool vis[1000][1000];
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
void dfs(long a,long b,char im)
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
		for(k=0;k<4;k++)
		{
			 c=a+x[k];
			  d=b+y[k];
			if(c>=0&&c<m&&d>=0&&d<n&&!vis[c][d]&&grid[c][d]==im)
			{
		    	push_a(c+1);
				push_b(d+1);
			    vis[c][d]=1;
			  
			}
			 
			  
		}
	}
}
long find(char ch)
{
	long i;
	for(i=0;i<how;i++)
		if(ch==store[i])
			return i;
	store[how++]=ch;
	return how-1;
}
int main()
{
	char c;
	long i,j,k,temp,kase=1,kas;
	scanf("%ld",&kas);
    while(kas--)
	{
		scanf("%ld %ld",&m,&n);
		memset(vis,0,sizeof(vis));
		memset(val,0,sizeof(val));
		t1=t2=how=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>grid[i][j];
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(!vis[i][j])
				{
					  k=find(grid[i][j]);
					  ch[k]=grid[i][j];
					  val[k]++;
					  dfs(i,j,grid[i][j]);
				
				}
			}
		}
		for(i=0;i<how;i++)
		{
			for(j=i+1;j<how;j++)
			{
				if(val[i]<val[j])
				{
					temp=val[i];
					val[i]=val[j];
					val[j]=temp;
					c=ch[i];
					ch[i]=ch[j];
					ch[j]=c;
				}
				else if(val[i]==val[j]&&ch[i]>ch[j])
				{
					c=ch[i];
					ch[i]=ch[j];
					ch[j]=c;
				}
			}
		}
		printf("World #%ld\n",kase++);
		for(i=0;i<how;i++)
		printf("%c: %ld\n",ch[i],val[i]);
	}
	return 0;
}