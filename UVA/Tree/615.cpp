#include<cstdio>
#include<queue>
#include<vector>

#define SIZE 500000

using namespace std;
	
typedef queue<long> qi;
typedef vector<long> vi;
qi q;
vi gr[SIZE];
long n,fu,list[SIZE],in[SIZE];
bool vis[SIZE],test[SIZE]; 
void init()
{
    long i;
    
    for(i=0; i<=n; i++)
    {
        gr[i].clear();
    }
    memset(vis,0,sizeof(vis));
	memset(test,0,sizeof(test));
}


bool bfs(long start)
{
	bool fl=0;
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
	if(count==n)
		return 1;
    return 0;
}
int main()
{
	bool yes,flag;
    long k=1,i,s,c,a,b;
    while(1)
    {
        scanf("%ld %ld",&a,&b);
		if(a<0&&b<0)
			break;
		n=0;
		memset(in,0,sizeof(in));
		i=0;
		yes=1;
        while(1)
		{
            if(!a&&!b)
				break;
            gr[a].push_back(b);
			
			if(!test[a])
			{
				list[i++]=a;
				n++;
			}
			if(!test[b])
			{
				list[i++]=b;
				n++;
			}
			if(in[b])
				yes=0;
			in[b]++;
			test[a]=test[b]=1;
			scanf("%ld %ld",&a,&b);
        }
		if(n==0)
			yes=1;
		else
		{
		if(yes)
		{
		for(i=0;i<n;i++)
		{
				if(in[list[i]]>1)
				{
					yes=0;
					break;
				}
				memset(test,0,sizeof(test));
				test[list[i]]=1;
			for(long j=0;j<gr[list[i]].size();j++)
			{
				if(test[gr[list[i]][j]])
				{
					yes=0;
					break;
				}
				test[gr[list[i]][j]]=1;
			}
			if(!yes)
				break;
		}
		}
		if(yes)
		{
		c=0;
		long ag=0;
		for(i=0;i<n;i++)
		{
				memset(vis,0,sizeof(vis));
			flag=bfs(list[i]);
			if(flag)
			{
				s=list[i];
				c++;
			}
			else 
				ag++;
		
			if(c>1)
			{
				yes=0;
				break;
			}
		}
		if(ag==n)
			yes=0;
		}
		}
		if(yes)
				printf("Case %ld is a tree.\n",k++);
		else
				printf("Case %ld is not a tree.\n",k++);
        init();
    }
    return 0;    
}
