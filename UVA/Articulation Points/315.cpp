//Finding Articulation point

#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
#define INF 200000000
typedef vector <long>vi;
vi grap[1000];
long tim,d[1000],low[1000],A,cnt;
bool vis[1000],found[1000];
void dfs(long cur)
{
     long i,next;
     tim++;
     d[cur]=tim;
     vis[cur]=1;
     for(i=0;i<grap[cur].size();i++)
     {
       next=grap[cur][i];
       if(!vis[next])
       {
         dfs(next);
         if(low[next]>=d[cur]&&!found[cur])
         {
             A++;
             found[cur]=1;
         }
         if(!cur)
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
    long i,n,e,a,b;
    char str[1000],*pch;
    while(scanf("%ld",&n)==1&&n)
    {
        getchar();
        while(gets(str)&&str[0]!='0')
        {
          pch=strtok(str," ");
          a=atol(pch);
          a--;
          pch=strtok(NULL," ");
          while(pch!=NULL)
          {
            b=atol(pch);
            b--;
            grap[a].push_back(b);
            grap[b].push_back(a);
            pch=strtok(NULL," ");
          }
        }
        for(i=0;i<n;i++)
        {found[i]=vis[i]=0;low[i]=INF;}
        tim=A=cnt=0;
        for(i=0;i<n;i++)
         if(!vis[i])
          dfs(i); 
         if(cnt<2)
          A--;
         printf("%ld\n",A);
        for(i=0;i<n;i++)
        {grap[i].clear();}
                         
    }
    return 0;
}
