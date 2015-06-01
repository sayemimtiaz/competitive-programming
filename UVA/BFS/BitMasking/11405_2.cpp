#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define INF 100000000
struct State
{
  int x,y;
  int p,m;
}S,A;
queue<State>q;
bool vis[300][10][10];
int D,move,C[10][10];
char str[50][50];
int x[8]={-2,-2, 2, 2,-1,-1, 1,1};
int y[8]={-1, 1,-1, 1,-2, 2,-2,2};

bool bfs()
{
	 int c,d,i;
	 while(!q.empty())
	 {
       S=q.front();
       q.pop();
      if(S.p==D)
       return 1;
     for(i=0;i<8;i++)
     {
			c=S.x+x[i];d=S.y+y[i];
			if(c<0||d<0||c>7||d>7||(str[c][d]!='.'&&str[c][d]!='P')||S.m+1>move)
			 continue;
			 A.p=S.p;
		    if(str[c][d]=='P')
			 A.p=S.p|(1<<C[c][d]);
		    if(vis[A.p][c][d])
		     continue;
		    A.x=c,A.y=d,A.m=S.m+1;
            q.push(A);
            vis[A.p][c][d]=1;
			
      }
   }
      return 0;
}

int main()
{
	int i,j,k,kase,P;
	scanf("%d",&kase);
	while(kase--)
	{
		scanf("%d",&move);
		getchar();
		P=0;
		for(i=0;i<8;i++)
		{
			gets(str[i]);
			for(j=0;j<8;j++)
			{
                if(str[i][j]=='k')
				{
                  S.x=i,S.y=j,S.p=0,S.m=0;
                  q.push(S);
                }
				else if(str[i][j]=='P'){
                  C[i][j]=P;
					P++;
                }
			}
		}
		D=(1<<P)-1;
		if(bfs())
			printf("Yes\n");
		else
		    printf("No\n");
		while(!q.empty())
		   q.pop();
       memset(vis,0,sizeof(vis));
	}
	return 0;
}
