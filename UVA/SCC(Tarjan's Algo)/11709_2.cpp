#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef vector <long>vi;
vi grap1[1200],grap2[1200];
struct S
{
  long node;
  long f;
}N[1200];
long tim,n;
bool vis[1200];
char store[1200][30];
int cmp(const void *a,const void *b)
{
    S *x=(S*)a;
    S *y=(S*)b;
    return (y->f-x->f);
}
int cmp1(const void *a,const void *b)
{
    return (strcmp((char*)a,(char*)b));
}
long binser(char *str)
{
     long beg,end,mid,h;
     beg=0;end=n-1;
     while(beg<=end)
     {
       mid=(beg+end)/2;
       h=strcmp(str,store[mid]);
       if(!h)
        return mid;
       if(h>0)
        beg=mid+1;
       else
         end=mid-1;
     }
}
void dfs1(long cur)
{
     long i,next;
     tim++;
     vis[cur]=1;
     for(i=0;i<grap1[cur].size();i++)
     {
       next=grap1[cur][i];
       if(!vis[next])
         dfs1(next);
     }
     tim++;
     N[cur].f=tim;
}
void dfs2(long cur)
{
     long i,next;
     vis[cur]=1;
     for(i=0;i<grap2[cur].size();i++)
     {
       next=grap2[cur][i];
       if(!vis[next])
         dfs2(next);
     }
}
int main()
{
    long i,e,a,b,cnt;
    char s1[30],s2[30];
    while(scanf("%ld %ld",&n,&e)==2&&(n||e))
    {
        getchar();
        for(i=0;i<n;i++)
           gets(store[i]);
        qsort(store,n,sizeof(store[0]),cmp1);
        for(i=0;i<n;i++)
        {
           vis[i]=0;
           N[i].node=i;
        }
        for(i=0;i<e;i++)
        {
          gets(s1);
          gets(s2);
          a=binser(s1);
          b=binser(s2);
          grap1[a].push_back(b);
          grap2[b].push_back(a);
        }
        tim=0;
        for(i=0;i<n;i++)
         if(!vis[i])
          dfs1(i);
        qsort(N,n,sizeof(S),cmp);
        memset(vis,0,sizeof(vis));
        cnt=0;
        for(i=0;i<n;i++)
        {
           if(!vis[N[i].node])
           { dfs2(N[i].node);
             cnt++;
           }
        }
        printf("%ld\n",cnt);
        for(i=0;i<n;i++)
        { grap1[i].clear();grap2[i].clear();}
                         
    }
    return 0;
}
