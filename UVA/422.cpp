#include<stdio.h>
#include<string.h>
long x[]={0,0,1,-1,-1,1,-1,1};
long y[]={1,-1,0,0,-1,1,1,-1};
long row,ox,oy;
char word[10000],grid[1000][1000];
bool check(long tx,long ty)
{
	long c,d,i;
	for(i=1;word[i]!='\0';i++)
	{
		c=tx+ox;d=ty+oy;
		if(c>0&&d>0&&c<=row&&d<=row&&word[i]==grid[c][d])
		{
			ox=c;oy=d;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	long i,j,k;
	bool flag;
	scanf("%ld",&row);
	for(i=1;i<=row;i++)
	{
		getchar();
		for(j=1;j<=row;j++)
			scanf("%c",&grid[i][j]);
	}
	getchar();
		while(gets(word)&&strcmp(word,"0"))
		{
			for(i=1;i<=row;i++)
			{
				flag=0;
				for(j=1;j<=row;j++)
				{
					if(grid[i][j]==word[0])
					{
						for(k=0;k<8;k++)
						{
							ox=i;oy=j;
						    if((flag=check(x[k],y[k])))
								break;
						}
						if(flag)
							break;
					}
					if(flag)
						break;
				}
				if(flag)
					break;
			}
		if(flag)
		printf("%ld,%ld %ld,%ld\n",i,j,ox,oy);
		else
			printf("Not found\n");
		}
	return 0;
}