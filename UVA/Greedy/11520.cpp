#include<stdio.h>
int main()
{
	char grid[20][20];
	long i,j,k,c,d,kase,n,kas=1;
	long x[]={0,0,1,-1};
	long  y[]={1,-1,0,0};
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<n;j++)
			   scanf("%c",&grid[i][j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(grid[i][j]=='.')
				{
					bool flag[200]={0};
					for(k=0;k<4;k++)
					{
						c=i+x[k];d=j+y[k];
						if(c>=0&&d>=0&&c<n&&d<n&&grid[c][d]!='.')
							flag[grid[c][d]]=1;
					}
					for(k='A';k<='Z';k++)
						if(!flag[k])
						{
							grid[i][j]=k;
							break;
						}
				}
			}
		}
		printf("Case %ld:\n",kas++);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%c",grid[i][j]);
			printf("\n");
		}
	}
	return 0;
}
