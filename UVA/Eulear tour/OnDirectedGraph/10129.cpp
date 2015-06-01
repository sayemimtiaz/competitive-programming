#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<cctype>
#include<string>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

bool flag,vis[30];
int n;
vector<int>C[50];
queue<int>q;
inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int bfs()
{
  int cnt=0,a,i,b;
  while(!q.empty())
  {
    a=q.front();
    q.pop();
    cnt++;
  for(i=C[a].size()-1;i>=0;i--)
  {
     b=C[a][i];
     if(!vis[b])
     {
      q.push(b);
      vis[b]=1;
      }
  }
  }
  return (cnt==n)?0:1;
}
int main()
{
    char str[5000];
    int kase,i,a,b,s,j;
    scanf("%d",&kase);
    while(kase--)
    {
      bool ace[30]={0};
      int in[30]={0},out[30]={0};
      scanf("%d",&n);
      for(j=0;j<n;j++)
      {
        scanf("%s",str);
        for(i=1;str[i]!='\0';i++);
        a=str[0]-'a',b=str[i-1]-'a';
        C[a].push_back(b);
        C[b].push_back(a);
        in[b]++;
        out[a]++;
        ace[a]=ace[b]=1;
      }
      flag=0;n=0;a=b=-1;
      for(i=0;i<26;i++)
        if(ace[i])
        {
          n++;
          s=i;
          if(in[i]!=out[i])
          {
           if(a==-1)
             a=i;
           else if(b==-1) 
            b=i;
            else
             flag=1;
           }
        }
      if(!flag)
      {
       if(a!=-1&&((out[a]-in[a]==1&&in[b]-out[b]==1)||(in[a]-out[a]==1&&out[b]-in[b]==1)))
        flag=0;
       else if(a!=-1)
        flag=1;
       if(!flag)
       {
       q.push(s);
       vis[s]=1;
       flag=bfs();
       }
       }
      
      if(flag)
       printf("The door cannot be opened.\n");
      else
       printf("Ordering is possible.\n");
       for(i=0;i<30;i++)
        C[i].clear(),vis[i]=0;
    }
    return 0;
}
