#include<cstdio>
#include<queue>
#include<vector>

#define SIZE 50000

using namespace std;
	
typedef queue<long> qi;
typedef vector<long> vi;

qi q;
vi gr[SIZE];
char store[SIZE][10];
long par[SIZE],glo,b;
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
long find(char *a)
{
	long i;
	for(i=0;i<glo;i++)
		if(strcmp(a,store[i])==0)
			return i;
	strcpy(store[glo],a);
	glo++;
	return glo-1;
}
bool bfs(long start)
{
	bool flag=0;
    long i,u,next;
    vis[start]=true;
    q.push(start);
    while(!q.empty())
    {
		u=q.front();
        q.pop();
		if(u==b)
			flag=1;
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
	
    return flag;
}

void path(long a,long c)
{
	if(a==c)
	return;
	path(a,par[c]);
	printf("%s %s\n",store[par[c]],store[c]);
}

int main()
{
	bool flag=0,flag2;
	char s1[1000],s2[1000];
    long i,a,n;
    while( scanf("%ld",&n)==1)
    {
		glo=0;
        for(i=0; i<n; i++)
        {
            scanf("%s %s",s1,s2);
            a=find(s1);
			b=find(s2);
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        scanf("%s %s",s1,s2);
	    a=find(s1);
		b=find(s2);
		flag2=bfs(a);
		if(flag)
		  printf("\n");
		flag=1;
		if(flag2)
		path(a,b);
		else
			printf("No route\n");
		memset(vis,0,sizeof(vis));
		init();
	
    }
    return 0;    
}
