#include<stdio.h>
#include<string.h>
#include<iostream.h>
long m,n,s1[10000],s2[10000],t1,t2,val[10000];
int x[8]={0,0,1,-1};
int y[8]={1,-1,0,0};
char grid[500][500],ch[10000];
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
long dfs(long a,long b,char im)
{
	long c,d,k,count=0;
	push_a(0);
	push_b(0);
	push_a(a+1);
	push_b(b+1);
	vis[a][b]=1;
	while(a=pop_a())
	{
		count++;
		b=pop_b();
		a--;b--;
		c=a;d=b;
		for(k=0;k<8;k++)
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
	return count;
}
int main()
{
	char c;
	long i,j,k,temp,kase=1;
    while(1)
	{
		scanf("%ld %ld",&m,&n);
		if(!m&&!n)
			break;
		memset(vis,0,sizeof(vis));
		t1=t2=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='.')
					vis[i][j]=1;
			}
		}
		k=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(vis[i][j]==0)
				{
					  ch[k]=grid[i][j];
					  val[k++]=dfs(i,j,grid[i][j]);
				
				}
			}
		}
		for(i=0;i<k;i++)
		{
			for(j=i+1;j<k;j++)
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
		printf("Problem %ld:\n",kase++);
		for(i=0;i<k;i++)
		printf("%c %ld\n",ch[i],val[i]);
	}
	return 0;
}