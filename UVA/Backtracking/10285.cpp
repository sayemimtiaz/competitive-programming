#include<stdio.h>
long x[4]={0,0,1,-1};
long y[4]={1,-1,0,0};
long save,row,col,grid[200][200];
void check(long a,long b,long how)
{
	if(how>save)
		save=how;
	long c,d,i;
	for(i=0;i<4;i++)
	{
		c=a+x[i];d=b+y[i];
		if(c<row&&d<col&&c>=0&&d>=0&&grid[a][b]>grid[c][d])
			check(c,d,how+1);
	}
}
int main()
{
	char area[60000];
	long kase,i,j;
	scanf("%ld",&kase);
	while(kase--)
	{
		save=-1000000;
		scanf("%s %ld %ld",area,&row,&col);
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				scanf("%ld",&grid[i][j]);
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				check(i,j,1);
		printf("%s: %ld\n",area,save);
	}
	return 0;
}