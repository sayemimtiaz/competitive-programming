#include<stdio.h>
#include<string.h>
#include<iostream.h>
char grid[100][100];
int board[100][100];
bool input()
{
	memset(board,0,sizeof(board));
	long i,j,cnt=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='k')
				board[i][j]=1;
			else if(grid[i][j]=='K')
				board[i][j]=2;
			else if(grid[i][j]>='a'&&grid[i][j]<='z')
				board[i][j]=5;
			else if(grid[i][j]=='.')
				cnt++;
			else
				board[i][j]=7;
		}
	}
	if(cnt==64)
		return false;
	return true;
}
bool color(long a,long b)
{
	long x,y;
	switch(grid[a][b])
	{
	case 'p':
		x=a+1;y=b-1;
		if(x<8&&y>=0&&board[x][y]==2)
				return 1;
		y=b+1;
		if(x<8&&y<8&&board[x][y]==2)
				return 1;
		break;
	case 'P':
		x=a-1;y=b-1;
		if(x>=0&&y>=0&&board[x][y]==1)
				return 1;
		y=b+1;
		if(x>=0&&y<8&&board[x][y]==1)
				return 1;
			break;
	case 'n':
		x=a-1;y=b-2;
		if(x>=0&&y>=0&&board[x][y]==2)
				return 1;
		y=b+2;
		if(x>=0&&y<8&&board[x][y]==2)
				return 1;
		x=a-2;y=b-1;
		if(x>=0&&y>=0&&board[x][y]==2)
				return 1;
		y=b+1;
		if(x>=0&&y<8&&board[x][y]==2)
				return 1;
		x=a+1;y=b-2;
		if(x<8&&y>=0&&board[x][y]==2)
				return 1;
		y=b+2;
		if(x<8&&y<8&&board[x][y]==2)
				return 1;
		x=a+2;y=b-1;
		if(x<8&&y>=0&&board[x][y]==2)
				return 1;
		y=b+1;
		if(x<8&&y<8&&board[x][y]==2)
				return 1;
		break;
	case 'N':
		x=a-1;y=b-2;
		if(x>=0&&y>=0&&board[x][y]==1)
				return 1;
		y=b+2;
		if(x>=0&&y<8&&board[x][y]==1)
				return 1;
		x=a-2;y=b-1;
		if(x>=0&&y>=0&&board[x][y]==1)
				return 1;
		y=b+1;
		if(x>=0&&y<8&&board[x][y]==1)
				return 1;
		x=a+1;y=b-2;
		if(x<8&&y>=0&&board[x][y]==1)
				return 1;
		y=b+2;
		if(x<8&&y<8&&board[x][y]==1)
				return 1;
		x=a+2;y=b-1;
		if(x<8&&y>=0&&board[x][y]==1)
				return 1;
		y=b+1;
		if(x<8&&y<8&&board[x][y]==1)
				return 1;
		break;
	case 'b':
			for(x=a+1,y=b-1;x<8&&y>=0;x++,y--)
					if(board[x][y])
				break;
			if(x<8&&y>=0&&board[x][y]==2)
				return 1;
		for(x=a+1,y=b+1;x<8&&y<8;x++,y++)
				if(board[x][y])
				break;
			if(x<8&&y<8&&board[x][y]==2)
				return 1;
		for(x=a-1,y=b-1;x>=0&&y>=0;x--,y--)
				if(board[x][y])
				break;
			if(x>=0&&y>=0&&board[x][y]==2)
				return 1;
		for(x=a-1,y=b+1;x>=0&&y<8;x--,y++)
				if(board[x][y])
				break;
			if(x>=0&&y<8&&board[x][y]==2)
				return 1;
		break;
		
	case 'B':
			for(x=a+1,y=b-1;x<8&&y>=0;x++,y--)
					if(board[x][y])
				break;
			if(x<8&&y>=0&&board[x][y]==1)
				return 1;
		for(x=a+1,y=b+1;x<8&&y<8;x++,y++)
				if(board[x][y])
				break;
			if(x<8&&y<8&&board[x][y]==1)
				return 1;
		for(x=a-1,y=b-1;x>=0&&y>=0;x--,y--)
				if(board[x][y])
				break;
			if(x>=0&&y>=0&&board[x][y]==1)
				return 1;
		for(x=a-1,y=b+1;x>=0&&y<8;x--,y++)
				if(board[x][y])
				break;
			if(x>=0&&y<8&&board[x][y]==1)
				return 1;
		break;
	case 'r':
		
		for(x=a-1;x>=0;x--)
			if(board[x][b])
				break;
			if(x>=0&&board[x][b]==2)
				return 1;
		for(x=a+1;x<8;x++)
			if(board[x][b])
				break;
			if(x<8&&board[x][b]==2)
				return 1;
			
		for(x=b-1;x>=0;x--)
			if(board[a][x])
				break;
			if(x>=0&&board[a][x]==2)
				return 1;
			
		for(x=b+1;x<8;x++)
			if(board[a][x])
				break;
			if(x<8&&board[a][x]==2)
				return 1;
		break;
	case 'R':
		for(x=a-1;x>=0;x--)
			if(board[x][b])
				break;
			if(x>=0&&board[x][b]==1)
				return 1;
		for(x=a+1;x<8;x++)
			if(board[x][b])
				break;
			if(x<8&&board[x][b]==1)
				return 1;
			
		for(x=b-1;x>=0;x--)
			if(board[a][x])
				break;
			if(x>=0&&board[a][x]==1)
				return 1;
			
		for(x=b+1;x<8;x++)
			if(board[a][x])
				break;
			if(x<8&&board[a][x]==1)
				return 1;
		break;
	case 'q':
		
				for(x=a+1,y=b-1;x<8&&y>=0;x++,y--)
					if(board[x][y])
				break;
			if(x<8&&y>=0&&board[x][y]==2)
				return 1;
		for(x=a+1,y=b+1;x<8&&y<8;x++,y++)
				if(board[x][y])
				break;
			if(x<8&&y<8&&board[x][y]==2)
				return 1;
		for(x=a-1,y=b-1;x>=0&&y>=0;x--,y--)
				if(board[x][y])
				break;
			if(x>=0&&y>=0&&board[x][y]==2)
				return 1;
		for(x=a-1,y=b+1;x>=0&&y<8;x--,y++)
				if(board[x][y])
				break;
			if(x>=0&&y<8&&board[x][y]==2)
				return 1;
		
		for(x=a-1;x>=0;x--)
			if(board[x][b])
				break;
			if(x>=0&&board[x][b]==2)
				return 1;
		for(x=a+1;x<8;x++)
			if(board[x][b])
				break;
			if(x<8&&board[x][b]==2)
				return 1;
			
		for(x=b-1;x>=0;x--)
			if(board[a][x])
				break;
			if(x>=0&&board[a][x]==2)
				return 1;
			
		for(x=b+1;x<8;x++)
			if(board[a][x])
				break;
			if(x<8&&board[a][x]==2)
				return 1;
		break;
	case 'Q':
			for(x=a+1,y=b-1;x<8&&y>=0;x++,y--)
					if(board[x][y])
				break;
			if(x<8&&y>=0&&board[x][y]==1)
				return 1;
		for(x=a+1,y=b+1;x<8&&y<8;x++,y++)
				if(board[x][y])
				break;
			if(x<8&&y<8&&board[x][y]==1)
				return 1;
		for(x=a-1,y=b-1;x>=0&&y>=0;x--,y--)
				if(board[x][y])
				break;
			if(x>=0&&y>=0&&board[x][y]==1)
				return 1;
		for(x=a-1,y=b+1;x>=0&&y<8;x--,y++)
				if(board[x][y])
				break;
			if(x>=0&&y<8&&board[x][y]==1)
				return 1;
		
		for(x=a-1;x>=0;x--)
			if(board[x][b])
				break;
			if(x>=0&&board[x][b]==1)
				return 1;
		for(x=a+1;x<8;x++)
			if(board[x][b])
				break;
			if(x<8&&board[x][b]==1)
				return 1;
			
		for(x=b-1;x>=0;x--)
			if(board[a][x])
				break;
			if(x>=0&&board[a][x]==1)
				return 1;
			
		for(x=b+1;x<8;x++)
			if(board[a][x])
				break;
			if(x<8&&board[a][x]==1)
				return 1;
		break;
	case 'k':
		x=a;y=b;
		if(y-1>=0&&board[x][y-1]==2)
			return 1;
		if(y+1<8&&board[x][y+1]==2)
			return 1;
		if(x-1>=0&&board[x-1][y]==2)
			return 1;
		if(x+1<8&&board[x+1][y]==2)
			return 1;
		if(x-1>=0&&y-1>=0&&board[x-1][y-1]==2)
			return 1;
		if(x-1>=0&&y+1<8&&board[x-1][y+1]==2)
			return 1;
		if(x+1<8&&y-1>=0&&board[x+1][y-1]==2)
			return 1;
		if(x+1<8&&y+1<8&&board[x+1][y+1]==2)
			return 1;
		break;
	case 'K':
			x=a;y=b;
		if(y-1>=0&&board[x][y-1]==1)
			return 1;
		if(y+1<8&&board[x][y+1]==1)
			return 1;
		if(x-1>=0&&board[x-1][y]==1)
			return 1;
		if(x+1<8&&board[x+1][y]==1)
			return 1;
		if(x-1>=0&&y-1>=0&&board[x-1][y-1]==1)
			return 1;
		if(x-1>=0&&y+1<8&&board[x-1][y+1]==1)
			return 1;
		if(x+1<8&&y-1>=0&&board[x+1][y-1]==1)
			return 1;
		if(x+1<8&&y+1<8&&board[x+1][y+1]==1)
			return 1;
		break;

	}
	return 0;
}
int main()
{
	bool flag;
	long kas=1,i,j;
	while(input())
	{
		flag=0;
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(board[i][j])
				{
					flag=color(i,j);
					if(flag)
						break;
				}
			}
			if(flag)
				break;
		}
		printf("Game #%ld: ",kas++);
		if(flag&&grid[i][j]>='a'&&grid[i][j]<='z')
			printf("white king is in check.\n");
		else if(flag)
			printf("black king is in check.\n");
		else
			printf("no king is in check.\n");

	}
	return 0;
}
