#include<stdio.h>
char str[1000000];
int main()
{
	int x[1000],y[1000];
	x['A']=-1;y['A']=0;x['B']=1;y['B']=0;x['R']=0;y['R']=1;x['L']=0;y['L']=-1;
	char grid[10][10];
	long i,j,kas=1,ei,ej,c,d;
	bool flag,ou=0;
	while(1)
	{
		flag=0;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				scanf("%c",&grid[i][j]);
				if(!i&&!j&&grid[i][j]=='Z')
				{
					flag=1;
					break;
				}
				else if(grid[i][j]==' ')
				{ei=i;ej=j;}
			}
			getchar();
			if(flag)
				break;
		}
		if(flag)
			break;
		flag=0;
		bool l=0;
		while(1)
		{
			gets(str);
			for(i=0;str[i]!='\0';i++)
			{
			if(str[i]=='0')
			{
				l=1;
				break;
			}
			if(flag)
				continue;
			if(str[i]!='A'&&str[i]!='B'&&str[i]!='L'&&str[i]!='R')
			{
				flag=1;
				continue;
			}
			c=ei+x[str[i]];
			d=ej+y[str[i]];
			if(c>=0&&d>=0&&c<5&&d<5)
			{
				grid[ei][ej]=grid[c][d];
				grid[c][d]=' ';
				ei=c;ej=d;
			}
			else
				flag=1;
			}
			if(l)
				break;

		}
		if(ou)
			printf("\n");
		ou=1;
		printf("Puzzle #%ld:\n",kas++);
		if(flag)
			printf("This puzzle has no final configuration.\n");
		else
		{
			for(i=0;i<5;i++)
			{
				for(j=0;j<5;j++)
				{
				   printf("%c",grid[i][j]);
					if(j<4)
						printf(" ");;
				}
				printf("\n");
			}
		}
	}
	return 0;
}