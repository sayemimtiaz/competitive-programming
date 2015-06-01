#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
typedef vector<long>vi;
vi adj[200];
long n,s[200],a[200],save;
int col[200];
void color(long node,long black)
{
     	long i;
   if((black+n-node+1)<=save)
     return;
   if(node>n)
   {
     if(save<black)
     {
       save=black;
     for(i=0;i<black;i++)
      s[i]=a[i];
      }
      return;
     }
	bool found[5]={0};
	for(i=0;i<adj[node].size();i++)
	 found[col[adj[node][i]]]=1;
    if(!found[1])
    {
       col[node]=1;
       a[black]=node;
	   color(node+1,black+1);
	   col[node]=0;
    }
    col[node]=2;
	color(node+1,black);
	col[node]=0;
}
int main()
{
	long i,e,kase,u,v,j;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld %ld",&n,&e);
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&u,&v);
			adj[u].push_back(v);adj[v].push_back(u);
		}
		save=-100000;
		color(1,0);
		printf("%ld\n",save);
		for(i=0;i<save;i++)
		{
			if(i)
				printf(" ");
			printf("%ld",s[i]);
		}
			printf("\n");
		for(i=0;i<=n;i++)
			adj[i].clear();
	}
	return 0;
}
