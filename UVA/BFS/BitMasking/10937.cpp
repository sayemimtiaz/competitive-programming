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

#define pb push_back
#define mem(x) memset(x,sizeof(x),0)
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

struct State
{
 int x,y,p; 
}S,A;

queue<State>q;
int d[1030][55][55],C[55][55];
int n,m;
bool vis[1030][55][55];
bool block[55][55];
char str[100][100];
int x[]={0,0,1,-1,1,-1,1,-1};
int y[]={1,-1,0,0,1,-1,-1,1};

void bfs()
{
     int c,dd,i;
     while(!q.empty())
     {
       S=q.front(),q.pop();
       for(i=0;i<4;i++)
       {
         c=S.x+x[i],dd=S.y+y[i];
         if(c<0||dd<0||c>=n||dd>=m||block[c][dd])
          continue;
         A.p=S.p;
         if(str[c][dd]=='!')
          A.p=A.p|(1<<C[c][dd]);
         if(vis[A.p][c][dd])
          continue;
         vis[A.p][c][dd]=1;
         A.x=c,A.y=dd;
         d[A.p][c][dd]=d[S.p][S.x][S.y]+1;
         q.push(A);
       }
     }
}

int main()
{
    int P,i,j,k,l,c,dd,D,si,sj;
    
    while(scanf("%d %d",&n,&m)&&(n||m))
    {
      getchar();
      P=0;
      for(i=0;i<n;i++)
      {
        gets(str[i]);
        for(j=0;j<m;j++)
        {
          if(str[i][j]=='*')
          {
            for(k=0;k<8;k++)
            {
             c=i+x[k],dd=j+y[k];
             if(c>=0&&dd>=0&&c<n&&dd<m)
              block[c][dd]=1;
              }
              block[i][j]=1;
          }
          else if(str[i][j]=='@'){
           si=i,sj=j;
           d[0][i][j]=0;
           vis[0][i][j]=1;
           S.x=i,S.y=j;
           S.p=0,q.push(S);}
          else if(str[i][j]=='!')
           C[i][j]=P++;
          else if(str[i][j]!='.')
           block[i][j]=1;
        }
      }
      D=(1<<P)-1;
     if(!block[si][sj])
      bfs();
      if(vis[D][si][sj])
       printf("%d\n",d[D][si][sj]);
      else
       printf("-1\n");
       memset(vis,0,sizeof(vis));
       memset(block,0,sizeof(block));
    }
    return 0;
}
