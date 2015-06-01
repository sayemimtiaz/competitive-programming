#include<cstdio>
#include<queue>
#include<vector>

#define SIZE 50000

using namespace std;
	
typedef queue<long> qi;
typedef vector<long> vi;

qi q;
vi gr[SIZE];
char store[SIZE];
long par[SIZE],glo;
bool vis[SIZE]; 
void init()
{
    long i;
    for(i=0; i<glo; i++)
    {  
        gr[i].clear();
        par[i]=i;
    }
    memset(vis,0,sizeof(vis));
}
long find(char a)
{
	long i;
	for(i=0;i<glo;i++)
		if(a==store[i])
			return i;
	store[glo++]=a;
	return glo-1;
}
int bfs(long start)
{
    long i,u,next;
    vis[start]=true;
    q.push(start);
    while(!q.empty())
    {
		u=q.front();
        q.pop();
        for(i=0; i<gr[u].size(); i++)
        {
            next=gr[u][i];
            if(vis[next]==false)
            {
				
                q.push(next);
                vis[next]=true;
                par[next]=u;
            }    
        }
    }
	
    return 0;
}

void path(long a,long b)
{
	if(a!=b)
		path(a,par[b]);
	printf("%c",store[b]);
}

int main()
{
	bool flag=0;
	char s1[1000],s2[1000];
    long i,a,b,t,edge,n;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&edge);
		glo=0;
        for(i=0; i<n; i++)
        {
            scanf("%s %s",s1,s2);
            a=find(s1[0]);
			b=find(s2[0]);
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
		if(flag)
			printf("\n");
		flag=1;
		for(i=0;i<edge;i++)
		{
        scanf("%s %s",&s1,&s2);
		 a=find(s1[0]);
			b=find(s2[0]);
			bfs(a);
			path(a,b);

        memset(vis,0,sizeof(vis));
			printf("\n");
		}
			init();
	
    }
    return 0;    
}
