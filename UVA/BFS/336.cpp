
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define SIZE 50000


	
typedef queue<long> qi;
typedef vector<long> vi;

qi q;
vi gr[SIZE];
long d[SIZE],ttl,s,im[SIZE],a[SIZE],b[SIZE];
bool vis[SIZE]; 


void init()
{
    long i;
    for(i=0; i<SIZE; i++)
    {
        gr[i].clear();
    }
  

}


void bfs(long start)
{
    long i,u,next;
    vis[start]=true;
	im[start]=0;
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
				d[next]=d[u]+1;
				im[next]=0;
            }    
        }
    }
}



int main()
{
    long i,j,k,t,h,count,max;
	h=1;
	while(1)
	{
	
    scanf("%ld",&t);
	if(!t)
		break;
	init();
	 memset(im,0,sizeof(im));
    for(i=0;i<t;i++)
	{
       scanf("%ld%ld",&a[i],&b[i]);
       gr[a[i]-1].push_back(b[i]-1);
	   gr[b[i]-1].push_back(a[i]-1);
	   
	   if(!i)
	   {
		   if(a[i]<b[i])
		   max=b[i];
		   else
		   max=a[i];
	   }
	   else
	   {
		   if(max<a[i])
			   max=a[i];
		   if(max<b[i])
			   max=b[i];
	   }
	
	}

	i=0;
	while(1)
	{
        scanf("%ld%ld",&s,&ttl);
		if(!s&&!ttl)
		    break;
		for(i=0;i<t;i++)
		{
			im[a[i]-1]=-1;
			im[b[i]-1]=-1;
		}
      memset(d,0,sizeof(d));
      memset(vis,0,sizeof(vis));
	  if(im[s-1]==-1)
		bfs(s-1);
		count=0;
		for(k=0;k<max;k++)
		{
			if(d[k]>ttl||im[k]==-1)
				count++;
	    
		}
	printf("Case %ld: %ld nodes not reachable from node %ld with TTL = %ld.\n",h++,count,s,ttl);
    }
	}
    return 0;    
}
