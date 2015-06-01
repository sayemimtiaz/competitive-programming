#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define INF 1000000000
typedef queue<long>q;
q q1,q2;
long board[200][200],row,col;
bool block[200][200];
long xk[8]={0,0,1,-1,1,-1,1,-1};
long yk[8]={-1,1,0,0,1,-1,-1,1};
void bfs()
{
	long a,b,c,d,i;
	while(!q1.empty())
	{
		a=q1.front();b=q2.front();
		q1.pop();q2.pop();
		for(i=0;i<8;i++)
		{
			c=a+xk[i];d=b+yk[i];
			if(c>0&&d>0&&c<=row&&d<=col&&!block[c][d]&&(board[a][b]+1)<board[c][d])
			{
				board[c][d]=board[a][b]+1;
				q1.push(c);q2.push(d);
			}
		}

	}
}
int main()
{
	long x[8]={-2,-2, 2, 2,-1,-1, 1,1};
    long y[8]={-1, 1,-1, 1,-2, 2,-2,2};
	long si,sj,ei,ej,i,j,k,kase,c,d;
	char str;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld %ld",&row,&col);
		memset(block,0,sizeof(block));
		for(i=1;i<=row;i++)
		{
			getchar();
			for(j=1;j<=col;j++)
			{
				scanf("%c",&str);
				if(str=='Z')
				{
					for(k=0;k<8;k++)
					{
			             c=i+x[k];d=j+y[k];
						if(c>0&&d>0&&c<=row&&d<=col)
							block[c][d]=1;
					}
					block[i][j]=1;
				}
				else if(str=='A')
				{si=i;sj=j;board[i][j]=0;}
				else if(str=='B')
				{ei=i;ej=j;board[i][j]=INF;}
				else
					board[i][j]=INF;
			}
		}
		block[si][sj]=block[ei][ej]=0;
		q1.push(si);q2.push(sj);
		bfs();
		if(board[ei][ej]==INF)
			printf("King Peter, you can't go now!\n");
		else
		printf("Minimal possible length of a trip is %ld\n",board[ei][ej]);
	}
	return 0;
}
