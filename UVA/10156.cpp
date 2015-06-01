#include<stdio.h>
#include<string.h>
bool grid[500][500];
long idx[1000000],idy[1000000];
int main()
{
	char ch[10];
	long i,t,x,y,col,row,tur,com,j,cnt;
	while(scanf("%ld %ld %ld %ld",&row,&col,&tur,&com)==4)
	{
		memset(grid,0,sizeof(grid));
		for(i=0;i<tur;i++)
		{
			scanf("%ld %ld %ld",&t,&x,&y);
			idx[t-1]=x;
			idy[t-1]=y;
			grid[x][y]=1;
		}
		for(i=0;i<com;i++)
		{
			scanf("%ld %s",&t,ch);
			x=idx[t-1];y=idy[t-1];
			if(!strcmp(ch,"S"))
			{
				if((x+1)<row&&!grid[x+1][y])
				{
				   grid[x][y]=0;
				   grid[x+1][y]=1;
				   idx[t-1]=x+1;
				}
			}
			else if(!strcmp(ch,"N"))
			{
				if((x-1)>=0&&!grid[x-1][y])
				{
				   grid[x][y]=0;
				   grid[x-1][y]=1;
				   idx[t-1]=x-1;
				}
			}
			else if(!strcmp(ch,"E"))
			{
				if((y+1)<col&&!grid[x][y+1])
				{
				   grid[x][y]=0;
				   grid[x][y+1]=1;
				   idy[t-1]=y+1;
				}
			}
			else if(!strcmp(ch,"W"))
			{
				if((y-1)>=0&&!grid[x][y-1])
				{
				   grid[x][y]=0;
				   grid[x][y-1]=1;
				   idy[t-1]=y-1;
				}
			}
			else if(!strcmp(ch,"SE"))
			{
				if((y+1)<col&&(x+1)<row&&!grid[x+1][y+1])
				{
				   grid[x][y]=0;
				   grid[x+1][y+1]=1;
				   idy[t-1]=y+1;
				   idx[t-1]=x+1;
				}
			}
			else if(!strcmp(ch,"SW"))
			{
				if((x+1)<row&&(y-1)>=0&&!grid[x+1][y-1])
				{
				   grid[x][y]=0;
				   grid[x+1][y-1]=1;
				   idx[t-1]=x+1;idy[t-1]=y-1;
				}
			}
			else if(!strcmp(ch,"NE"))
			{
				if((x-1)>=0&&(y+1)<col&&!grid[x-1][y+1])
				{
				   grid[x][y]=0;
				   grid[x-1][y+1]=1;
				   idx[t-1]=x-1;idy[t-1]=y+1;
				}
			}
			else
			{	if((x-1)>=0&&(y-1)>=0&&!grid[x-1][y-1])
				{
				   grid[x][y]=0;
				   grid[x-1][y-1]=1;
				   idx[t-1]=x-1;idy[t-1]=y-1;
				}
			}

			
		}
		for(i=0;i<row;i++)
		{
			cnt=0;
			for(t=0;t<col;t++)
			{
				if(grid[i][t])
				{
					for(j=0;j<cnt;j++)
						putchar(' ');
					cnt=0;
					putchar('*');

				}
				else
					cnt++;
			}
			putchar('\n');
		}
		putchar('\n');

	}
	return 0;
}