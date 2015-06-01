#include<stdio.h>
long grid[200][200];
int main()
{
	long cnt, i,j,k,n;
	bool f=0;
	while(scanf("%ld",&n)==1)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%ld",&grid[i][j]);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					if((i>j&&j>k)||(i<j&&j<k))
					{
					if(grid[i][j]&&grid[j][k]&&grid[k][i])
					{
						cnt++;
						printf("%ld %ld %ld\n",i,j,k);
					}
					}
				}
			}
		}
		printf("total:%ld\n\n",cnt);
	}
	return 0;
}