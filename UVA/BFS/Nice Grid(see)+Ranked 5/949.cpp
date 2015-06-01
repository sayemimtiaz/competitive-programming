#include<cstdio>
#include<queue>
using namespace std;
#define INF 2000000000
typedef queue<long>qi;
qi q1,q2;
bool con[20000][110];
long x[4]={0,0,1,-1};
long y[4]={1,-1,0,0};
long tim[120][120],row,col,d[120][120];
void init()
{
	long i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			d[i][j]=INF;
			tim[i][j]=0;
		}
	memset(con,0,sizeof(con));
	d[0][0]=0;
}
void bfs(long i,long j)
{
	long c,m,a,b,f,k;
	q1.push(i);
	q2.push(j);
	while(!q1.empty())
	{
		a=q1.front();
		b=q2.front();
		q1.pop();q2.pop();
		for(k=0;k<4;k++)
		{
			c=a+x[k];
			m=b+y[k];
			if(c>=0&&m>=0&&c<row&&m<col&&!con[(a*row)+b][(c*row)+m])
			{
					f=1;
					if(tim[c][m]>d[a][b])
					f=tim[c][m]-d[a][b]+1;
					if((d[a][b]+f)<d[c][m])
					{
					q1.push(c);
	                q2.push(m);
					d[c][m]=d[a][b]+f;
					}
			}
		}
	}
}
int main()
{
	long i,r,x1,y1,x2,y2;
	while(scanf("%ld %ld",&row,&col)==2)
	{
		init();
		scanf("%ld",&r);
		for(i=0;i<r;i++)
		{
			scanf("%ld %ld %ld %ld",&x1,&y1,&x2,&y2);
			con[(x1*row)+y1][(x2*row)+y2]=1;
		}
	    scanf("%ld",&r);
		for(i=0;i<r;i++)
		{
			scanf("%ld %ld %ld",&y2,&x1,&y1);
			tim[x1][y1]=y2;
		}
		bfs(0,0);
		printf("%ld\n",d[row-1][col-1]);
	}
	return 0;
}