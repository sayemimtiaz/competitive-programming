#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;
typedef vector <long>vi;
map<string,int>m1;
map<int,string>m2;
vi grap1[120],grap2[120];
struct S
{
  int node;
  int f;
}N[120];
int tim,n;
bool vis[1200],flag;

int cmp(const void *a,const void *b)
{
    S *x=(S*)a;
    S *y=(S*)b;
    return (y->f-x->f);
}

void dfs1(int cur)
{
     int i,next;
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
void dfs2(int cur)
{
     int i,next;
     vis[cur]=1;
     if(flag)
      cout<<", ";
     else
      flag=1;
     cout<<m2[cur];
     for(i=0;i<grap2[cur].size();i++)
     {
       next=grap2[cur][i];
       if(!vis[next])
         dfs2(next);
     }
}
int main()
{
    int i,e,a,b,j,kas=1;
    bool lin=0;
    string s1,s2;
    while(cin>>n>>e&&(n||e))
    {
        memset(vis,0,sizeof(vis));
        j=0;
        for(i=0;i<e;i++)
        {
          cin>>s1>>s2;
          if(m1.find(s1)==m1.end())
          {
            m1[s1]=j;
            m2[j]=s1;
            N[j].node=j;
            a=j;j++;
          }
          else
           a=m1[s1];
          if(m1.find(s2)==m1.end())
          {
            m1[s2]=j;
            m2[j]=s2;
            N[j].node=j;
            b=j;j++;
          }
          else
          b=m1[s2];
          grap1[a].push_back(b);
          grap2[b].push_back(a);
        }
        tim=0;
        for(i=0;i<n;i++)
         if(!vis[i])
          dfs1(i);
        qsort(N,n,sizeof(S),cmp);
        memset(vis,0,sizeof(vis));
        if(lin)
         cout<<"\n";
        else
         lin=1;
        cout<<"Calling circles for data set "<<kas++<<":\n";
        for(i=0;i<n;i++)
        {
           if(!vis[N[i].node])
           {
            flag=0; 
            dfs2(N[i].node);
            cout<<"\n"; 
           }
        }
        m1.clear();m2.clear();
        for(i=0;i<n;i++)
         grap1[i].clear(),grap2[i].clear();
    }
    return 0;
}
          
