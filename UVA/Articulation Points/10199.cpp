#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#define INF 2000000000
using namespace std;
vector<long>adj[120];
long sor,cnt,n,d[120],tim,low[120],A,art[120];
bool vis[120],found[120];
char node[120][50];
int cmp(const void *a,const void *b)
{
  return (strcmp((char*)a,(char*)b));   
}
int cmp1(const void *a,const void *b)
{
  long *x=(long*)a;
  long *y=(long*)b;
  return *x-*y;   
}
long bin(char *str)
{
     long beg,end,mid,h;
     beg=0;end=n-1;
     while(beg<=end)
     {
        mid=(beg+end)/2;
        h=strcmp(str,node[mid]);
        if(!h)
        return mid;
        if(h>0)
        beg=mid+1;
        else
        end=mid-1;
     }
}
void dfs(long cur)
{
     long i,next;
     tim++;
     d[cur]=tim;
     vis[cur]=1;
     for(i=0;i<adj[cur].size();i++)
     {
       next=adj[cur][i];
       if(!vis[next])
       {
         dfs(next);
         if(low[next]>=d[cur]&&!found[cur]&&cur!=sor)
         {
            art[A++]=cur;
            found[cur]=1;
         }
         if(cur==sor)
          cnt++;
         if(low[next]<low[cur])
          low[cur]=low[next];
       }
        else if(d[next]<low[cur])
          low[cur]=d[next];
     }
     tim++;
}
int main()
{
    bool flag=0;
    long kas=1,i,e,u,v;
    char str[10000],s1[10000],s2[10000];
    while(scanf("%ld",&n)==1&&n)
    {
         getchar();
         for(i=0;i<n;i++)
          {low[i]=INF; gets(node[i]);}
         qsort(node,n,sizeof(node[0]),cmp);
         scanf("%ld",&e);
         getchar();
         while(e--)
         {
           gets(str);
           sscanf(str,"%s %s",s1,s2);
           u=bin(s1);v=bin(s2);
           adj[u].push_back(v);
           adj[v].push_back(u);
         }
         tim=A=cnt=0;
        for(i=0;i<n;i++)
        {
         if(!vis[i])
         {
          sor=i;cnt=0;
          dfs(i); 
          if(cnt>1)
           {art[A++]=sor;}
          }
        }
         if(flag)
          printf("\n");
         else
          flag=1;
         printf("City map #%ld: %ld camera(s) found\n",kas++,A);
         qsort(art,A,sizeof(long),cmp1);
         for(i=0;i<A;i++)
          printf("%s\n",node[art[i]]);
         for(i=0;i<n;i++)
         {found[i]=0;vis[i]=0;adj[i].clear();}
    }
    return 0;
}
