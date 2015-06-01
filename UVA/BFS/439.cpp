#include<cstdio>
#include<queue>
using namespace std;
#define INF 1000000000
typedef queue<long>q;
q q1,q2;
long board[10][10];
long x[8]={-1,1,-2,2,-1,1,-2,2};
long y[8]={-2,-2,-1,-1,2,2,1,1};
void bfs()
{
	long a,b,c,d,i;
	while(!q1.empty())
	{
		a=q1.front();b=q2.front();
		q1.pop();q2.pop();
		for(i=0;i<8;i++)
		{
			c=a+x[i];d=b+y[i];
			if(c>0&&d>0&&c<9&&d<9&&(board[a][b]+1)<board[c][d])
			{
				board[c][d]=board[a][b]+1;
				q1.push(c);q2.push(d);
			}
		}

	}
}
int main()
{
	long si,sj,ei,ej,i,j;
	char str[1000];
	while(gets(str))
	{
		si=str[1]-'0';sj=str[0]-96;
		ei=str[4]-'0';ej=str[3]-96;
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
				board[i][j]=INF;
		board[si][sj]=0;
		q1.push(si);q2.push(sj);
		bfs();
		printf("To get from %c%c to %c%c takes %ld knight moves.\n",str[0],str[1],str[3],str[4],board[ei][ej]);
	}
	return 0;
}
