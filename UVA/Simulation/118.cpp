#include<stdio.h>
int main()
{
	int i,sx,sy,urx,ury;
	char so,str[1000];
	bool lost;
	bool mark[100][100]={0,0};
	scanf("%d %d",&urx,&ury);
	getchar();
	while(gets(str))
	{
		sscanf(str,"%d %d %c",&sx,&sy,&so);
		gets(str);
		lost=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='R')
			{
				if(so=='E')
				 so='S';
				else if(so=='S')
				 so='W';
				else if(so=='W')
				 so='N';
				else 
				 so='E';
			}
			else if(str[i]=='L')
			{
				if(so=='E')
				so='N';
				else if(so=='S')
				 so='E';
				else if(so=='W')
				 so='S';
				else 
				 so='W';
			}
			else
			{
				if(so=='E')
				{
					sx=sx+1;
					if(sx>urx)
					{
						sx--;
						if(mark[sx][sy])
							continue;
						mark[sx][sy]=1;
						lost=1;
						break;
					}
				}
				else if(so=='S')
				{
					sy=sy-1;
					if(sy<0)
					{
						sy++;
						if(mark[sx][sy])
							continue;
						mark[sx][sy]=1;
						lost=1;
						break;
					}
				}
				else if(so=='W')
				{
					sx--;
					if(sx<0)
					{
						sx++;
						if(mark[sx][sy])
							continue;
						mark[sx][sy]=1;
						lost=1;
						break;
					}
				}
				else 
				{
					sy++;
					if(sy>ury)
					{
						sy--;
						if(mark[sx][sy])
							continue;
						mark[sx][sy]=1;
						lost=1;
						break;
					}
				}
			}
		}
		if(lost)
			printf("%d %d %c LOST\n",sx,sy,so);
		else
			printf("%d %d %c\n",sx,sy,so);
	}
	return 0;
}