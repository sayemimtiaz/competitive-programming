#include<stdio.h>
#include<ctype.h>
long x[]={0,0,1,-1,-1,1,-1,1};
long y[]={1,-1,0,0,-1,1,1,-1};
long row,col;
char word[10000],grid[1000][1000];
bool check(long ox,long oy,long tx,long ty)
{
	long c,d,i;
	for(i=1;word[i]!='\0';i++)
	{
		c=tx+ox;d=ty+oy;
		if(c>=0&&d>=0&&c<row&&d<col&&word[i]==grid[c][d])
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
	long i,j,k,kase,q;
	bool flag,fl=0;
	scanf("%ld",&kase);
	getchar();
	while(kase--)
	{
		scanf("%ld %ld",&row,&col);
		for(i=0;i<row;i++)
		{
			getchar();
			for(j=0;j<col;j++)
			{
				scanf("%c",&grid[i][j]);
				grid[i][j]=tolower(grid[i][j]);
			}
		}
		scanf("%ld",&q);
		getchar();
		if(fl)
			printf("\n");
		fl=1;
		while(q--)
		{
			gets(word);
			for(i=0;word[i]!='\0';i++)
				word[i]=tolower(word[i]);
			for(i=0;i<row;i++)
			{
				flag=0;
				for(j=0;j<col;j++)
				{
					if(grid[i][j]==word[0])
					{
						for(k=0;k<8;k++)
						    if((flag=check(i,j,x[k],y[k])))
								break;
						if(flag)
							break;
					}
					if(flag)
						break;
				}
				if(flag)
					break;
			}
		printf("%ld %ld\n",i+1,j+1);
		}
	}
	return 0;
}