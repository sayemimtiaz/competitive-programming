#include<stdio.h>
#include<string.h>
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
char grid[1000][1000],ch;
bool vis[1000][1000];
long t1,t2,row,col,s1[1000000],s2[1000000];
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
			if(c>=0&&c<row&&d>=0&&d<col&&!vis[c][d]&&grid[c][d]==im)
			{
				grid[c][d]=ch;
		    	push_a(c+1);
				push_b(d+1);
			    vis[c][d]=1;
			  
			}
			 
			  
		}
	}
}
int main()
{
	char str[10000],name[10000];
	long i,j,r,c,r1,c1,temp,hor,ver;
	while(gets(str))
	{
		if(str[0]=='X')
			break;
		switch(str[0])
		{
		case 'I':
			sscanf(str,"%*c %ld %ld",&col,&row);
			memset(grid,'O',sizeof(grid));
			break;
		case 'C':
			memset(grid,'O',sizeof(grid));
			break;
		case 'L':
			sscanf(str,"%*c %ld %ld %c",&c,&r,&ch);
			grid[r-1][c-1]=ch;
			break;
		case 'V':
			sscanf(str,"%*c %ld %ld %ld %c",&c,&r,&r1,&ch);
			if(r1<r)
			{
				temp=r1;
				r1=r;
				r=temp;
			}
			for(i=r-1;i<r1;i++)
				grid[i][c-1]=ch;
			break;
		case 'H':
			sscanf(str,"%*c %ld %ld %ld %c",&c,&c1,&r,&ch);
			if(c1<c)
			{
				temp=c1;
				c1=c;
				c=temp;
			}
			for(i=c-1;i<c1;i++)
				grid[r-1][i]=ch;
			break;
		case 'K':
			sscanf(str,"%*c %ld %ld %ld %ld %c",&c,&r,&c1,&r1,&ch);
			hor=c1-c;
			ver=r1-r;
			for(i=r-1;i<ver+r;i++)
				for(j=c-1;j<hor+c;j++)
					grid[i][j]=ch;
			break;
		case 'F':
			sscanf(str,"%*c %ld %ld %c",&c,&r,&ch);
			memset(vis,0,sizeof(vis));
			t1=t2=0;
			r--;c--;
			dfs(r,c,grid[r][c]);
			grid[r][c]=ch;
			break;
		case 'S':
			sscanf(str,"%*c %s",name);
			printf("%s\n",name);
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
					printf("%c",grid[i][j]);
				printf("\n");
			}
			break;
		default:
			break;

		}
	}
	return 0;
}
