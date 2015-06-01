#include<stdio.h>
int main()
{
	char str[50][50];
	long i,x,y,m,n,kase;
	char match[]={"IEHOVA#"};
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld %ld",&m,&n);
		getchar();
		for(i=0;i<m;i++)
			gets(str[i]);
		for(i=0;i<n;i++)
			if(str[m-1][i]=='@')
			{
				x=m-1;y=i;
				break;
			}
		i=0;
		while(str[x][y]!='#')
		{
			if(i)
				printf(" ");
			if((x-1)>=0&&str[x-1][y]==match[i])
			{
				x--;
				printf("forth");
			}
			else if((y+1)<n&&str[x][y+1]==match[i])
			{
				y++;
				printf("right");
			}
			else
			{
				y--;
				printf("left");
			}
			i++;

		}
		printf("\n");

	}
	return 0;
}
