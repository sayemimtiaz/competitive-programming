#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define INF 2147483647 
int adj[1000][1000],d[1000][1000];
bool visit[1000][1000];

int main()
{
	int n,r,c,i,x1,x2,y1,y2,j;
	int a[4]={1,-1,0,0};
	int b[4]={0,0,1,-1};
	priority_queue<pair<int,pair<int,int> > >pq;
	pair<int,pair<int,int> >nodo;
	
	scanf("%d",&n);
	while(n--)
	{
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			scanf("%d",&adj[i][j]);
			d[i][j]=-1;
		}
	d[0][0]=adj[0][0];
	pq.push(make_pair(-d[0][0],make_pair(0,0)));
	
	while(!pq.empty())
	{
		nodo=pq.top();pq.pop();
		x1=nodo.second.first;y1=nodo.second.second;
		if(visit[x1][y1])
		 continue;
		visit[x1][y1]=1;
		for(i=0;i<4;i++)
		{
			x2=x1+a[i];y2=y1+b[i];
			if(x2<0||y2<0||x2>=r||y2>=c)
			 continue;
			if(d[x2][y2]==-1||(d[x2][y2]>(adj[x2][y2]+d[x1][y1])))
			{
				d[x2][y2]=adj[x2][y2]+d[x1][y1];
				pq.push(make_pair(-d[x2][y2],make_pair(x2,y2)));
			}
		}
	}
	printf("%d\n",d[r-1][c-1]);
	memset(visit,0,sizeof(visit));
	}
	return 0;
}
