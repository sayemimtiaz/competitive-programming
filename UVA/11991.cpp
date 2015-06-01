#include<cstdio>
#include<vector>
#define SIZE 1000500
using namespace std;
vector<long>adj[SIZE];
int main()
{
    long i,n,m,a,k;
    while(scanf("%ld %ld",&n,&m)==2)
    {
       for(i=1;i<=n;i++)
       {
         scanf("%ld",&a);
         adj[a].push_back(i);
       }
       while(m--)
       {
         scanf("%ld %ld",&k,&a);
         if(adj[a].size()<k)
          printf("0\n");
         else
          printf("%ld\n",adj[a][k-1]);
       }
       for(i=1;i<=SIZE;i++)
        adj[i].clear();
    }
    return 0;
}
