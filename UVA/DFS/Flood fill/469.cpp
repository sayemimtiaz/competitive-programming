#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long col,row,s1[10000],s2[10000],t1,t2,a[100000],b[100000];
long x[8]={0,0,-1,1,-1,-1,1,1};
long y[8]={-1,1,0,0,-1,1,-1,1};
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
long dfs(long a,long b)
{
	long c,d,k,count=1;;
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
			if(c>=0&&c<row&&d>=0&&d<col&&!vis[c][d]&&grid[c][d]=='W')
			{
				count++;
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
	long kase,count,i,j,len,k,l;
	bool flag,yes=0;
	char ch[10000],str[10000];
	scanf("%ld\n",&kase);
	while(kase--)
	{
		row=l=0;
		while(gets(str))
		{
			len=strlen(str);
			if(len==0)
				break;
			if(str[0]>='0'&&str[0]<='9')
			{
				flag=1;
				k=0;
				for(i=0;i<=len;i++)
				{
					if(str[i]==' '||str[i]=='\0')
					{
						ch[k]='\0';
						if(flag)
						{
							flag=0;
						    a[l]=atol(ch);
						}
						else
							b[l++]=atol(ch);
						k=0;
					}
					else
						ch[k++]=str[i];
				}
			}
			else
			{
				col=len;
				for(i=0;i<len;i++)
					grid[row][i]=str[i];
				row++;
			}
			
		}
		if(yes)
			printf("\n");
		yes=1;
		for(i=0;i<l;i++)
		{
			memset(vis,0,sizeof(vis));
		    count=dfs(a[i]-1,b[i]-1);
			printf("%ld\n",count);
		}
	}
	return 0;
}