#include<cstdio>
#include<vector>
using namespace std;
vector<long>gr[100];
bool vis[100][100];
long maxo;
void check(long i,long cost)
{
	if(cost>maxo)
		maxo=cost;
	long j,a;
	for(j=0;j<gr[i].size();j++)
	{
		a=gr[i][j];
		if(!vis[i][a])
		{
			vis[i][a]=vis[a][i]=1;
			check(gr[i][j],cost+1);
			vis[i][a]=vis[a][i]=0;
		}
	}
}
int main()
{
	long n,e,i,a,b,j;
	while(scanf("%ld %ld",&n,&e)==2&&(n||e))
	{
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&a,&b);
			gr[a].push_back(b);gr[b].push_back(a);
		}
		maxo=-1000000;
		for(i=0;i<n;i++)
		{
			check(i,0);
		}
		printf("%ld\n",maxo);
		for(i=0;i<n;i++)
		{
			gr[i].clear();
			for(j=0;j<n;j++)
				vis[i][j]=0;
		}
	}
	return 0;
}