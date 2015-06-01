#include<cstdio>
#include<queue>
#include<vector>
#define SIZE 50000
using namespace std;
typedef queue<long> qi;
typedef vector<long> vi;
qi q;
vi gr[SIZE];
long n,day[SIZE],e,maxi;
bool vis[SIZE]; 
void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
        gr[i].clear();
    }
    memset(vis,0,sizeof(vis));
}


int bfs(long start)
{
    long i,u,next,d=2,count=0,im=0,save=1;
    vis[start]=true;
	day[start]=1;
    q.push(start);
    while(!q.empty())
    {
		u=q.front();
        q.pop();
		im++;
        for(i=0; i<gr[u].size(); i++)
        {
	
            next=gr[u][i];
            if(vis[next]==false)
            {
						
				count++;
				day[next]=d;
                q.push(next);
                vis[next]=true;
            }    
        }
		if(im!=save)
			continue;

		d++;
		save=count;
		im=0;
		if(maxi<count)
		{
			e=day[u];
			maxi=count;
		}
		count=0;

    }
    return 0;
}



int main()
{
    long i,a,b,j;
    while( scanf("%ld",&n)==1)
    {
		init();
        for(i=0; i<n; i++)
        {
            scanf("%ld",&a);
			for(j=0;j<a;j++)
			{
				scanf("%ld",&b);
            
                gr[i].push_back(b);
			}
        }
		scanf("%ld",&a);
		while(a--)
		{
			maxi=0;
			scanf("%ld",&b);
		    bfs(b);
		    if(maxi==0)
			  printf("%ld\n",maxi);
			else
		      printf("%ld %ld\n",maxi,e);
			memset(vis,0,sizeof(vis));
		}
    }
    return 0;    
}
