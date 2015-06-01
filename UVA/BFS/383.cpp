#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef vector<long>vi;
typedef queue<long>qi;
vi adj[50];
qi q;
char node[50][3];
bool vis[50];
long d[50],m;
int cmp(const void *a,const void *b)
{
	return (strcmp((char*)a,(char*)b));
}
long binser(char *str)
{
      long s,e,h,mid;
      s=0;e=m-1;
       while(s<=e)
       {
         mid=(s+e)/2;
         h=strcmp(str,node[mid]);
         if(!h)
           return mid;
         if(h>0)
          s=mid+1;
         else
          e=mid-1;
       }
}
void bfs()
{
     long a,b,i;
     while(!q.empty())
     {
        a=q.front();
        q.pop();
         for(i=0;i<adj[a].size();i++)
         {
            b=adj[a][i];
            if(!vis[b])
            {
              d[b]=d[a]+1;
              q.push(b);
              vis[b]=1;
            }
         }
     }
                      
}
int main()
{
    long j,kase,kas=1,u,v,i,unit,n,p;
    char s1[100],s2[100],str[1000];
    scanf("%ld",&kase);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    while(kase--)
    {
        scanf("%ld %ld %ld",&m,&n,&p);
        for(i=0;i<m;i++)
        scanf("%s",node[i]);
        qsort(node,m,sizeof(node[0]),cmp);
        getchar();
        for(i=0;i<n;i++)
        {
            gets(str);
            sscanf(str,"%s %s",s1,s2);
            u=binser(s1);
            v=binser(s2);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        printf("DATA SET  %ld\n\n",kas++);
        for(i=0;i<p;i++)
        {
            gets(str);
            sscanf(str,"%ld %s %s",&unit,s1,s2);
            u=binser(s1);v=binser(s2);
            memset(vis,0,sizeof(vis));
            for(j=0;j<m;j++)
             d[j]=0;
            q.push(u);vis[u]=1;
            bfs();
            if(d[v])
             printf("$%ld\n",d[v]*unit*100);
            else
              printf("NO SHIPMENT POSSIBLE\n");
        }
        printf("\n");
        for(i=0;i<m;i++)
         adj[i].clear();
    }
    printf("END OF OUTPUT\n");
    return 0;
}
