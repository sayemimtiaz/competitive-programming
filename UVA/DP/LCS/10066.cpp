#include<stdio.h>
long c[1000][1000],b[1000][1000],m,n;
long s1[10000],s2[10000];
void lcs()
{
	long i,j;
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=0;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;

			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
			}
			else
			{
                c[i][j]=c[i][j-1];
			}
		}
	}
	printf("%ld\n\n",c[m][n]);
}
int main()
{
	long i,kas=1;
	while(scanf("%ld %ld",&m,&n)==2&&m&&n)
	{
		for(i=0;i<m;i++)
			scanf("%ld",&s1[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&s2[i]);
		printf("Twin Towers #%ld\nNumber of Tiles : ",kas++);
	lcs();
	}
	return 0;
}
