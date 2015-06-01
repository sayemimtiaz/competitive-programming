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

int C[21][21];
int n,m,d[32770][21][21];
bool vis[32770][21][21];
char str[100][100];
int x[]={0,0,1,-1,1,-1,1,-1};
int y[]={1,-1,0,0,1,-1,-1,1};

void bfs()
{
     int c,dd,i;
     while(!q.empty())
     {
       S=q.front(),q.pop();
       for(i=0;i<8;i++)
       {
         c=S.x+x[i],dd=S.y+y[i];
         if(c<0||dd<0||c>=n||dd>=m)
          continue;
         A.p=S.p;
         if(str[c][dd]=='#')
          A.p=A.p|(1<<C[c][dd]);
         if(vis[A.p][c][dd])
          continue;
         d[A.p][c][dd]=d[S.p][S.x][S.y]+1;
         vis[A.p][c][dd]=1;
         A.x=c,A.y=dd;
         q.push(A);
       }
     }
}

int main()
{
    int P,i,j,k,l,c,dd,D,si,sj;
    
    while(~scanf("%d %d",&n,&m))
    {
      getchar();
      P=0;
      for(i=0;i<n;i++)
      {
        gets(str[i]);
        for(j=0;j<m;j++)
        {
          if(str[i][j]=='L'){
           si=i,sj=j;
           d[0][i][j]=0;
           vis[0][i][j]=1;
           S.x=i,S.y=j;
           S.p=0,q.push(S);}
          else if(str[i][j]=='#')
           C[i][j]=P++;
        }
      }
      D=(1<<P)-1;
      bfs();
      printf("%d\n",d[D][si][sj]);
      rep(i,0,D+1)
       rep(j,0,n)
        rep(k,0,m)
         vis[i][j][k]=0;
    }
    return 0;
}
