
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>

#define SIZE 500000

using namespace std;
	
typedef queue<long> qi;
typedef vector<long> vi;
char store[6000][50];
qi q;
vi gr[SIZE];
bool vis[SIZE]; 

long n;

void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
        gr[i].clear();
    }
    memset(vis,0,sizeof(vis));
}


long bfs(long start)
{
    long i,u,next,count=0;
    vis[start]=true;
    q.push(start);
    while(!q.empty())
    {
		count++;
		u=q.front();
        q.pop();
        for(i=0; i<gr[u].size(); i++)
        {
            next=gr[u][i];
            if(vis[next]==false)
            {
				
                q.push(next);
                vis[next]=true;
            }    
        }
    }
	
    return count;
}
int comp(const void *a,const void *b)
{
	char *x=(char*)a;
	char *y=(char*)b;
	return strcmp(x,y);
}

long find(char *s)
{
	long start,end,mid;
	start=0;
	end=n-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(!strcmp(store[mid],s))
			return mid;
		else if(strcmp(store[mid],s)>0)
			end=mid-1;
		else
			start=mid+1;

	}
}
int main()
{
	char s1[1000],s2[1000];
    long i,a,b,edge,count,max;
    while(1)
    {
		scanf("%ld %ld",&n,&edge);
		if(!n&&!edge)
			break;
		init();
		for(i=0;i<n;i++)
			scanf("%s",store[i]);
		qsort((void*)store,n,sizeof(store[0]),comp);
        for(i=0; i<edge; i++)
        {
            scanf("%s %s",s1,s2);
            a=find(s1);
			b=find(s2);
            gr[a].push_back(b);
            gr[b].push_back(a);
		}
		max=-100000;
		for(i=0;i<n;i++)
		{
			if(vis[i]==false)
			{
               count=bfs(i);
			}
			if(max<count)
				max=count;
        }
		printf("%ld\n",max);
    }
    return 0;    
}
