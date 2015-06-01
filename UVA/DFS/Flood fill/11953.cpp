#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef queue<long>qi;
qi q1,q2;
char grid[120][120];
bool vis[120][120];
long n;
int x[8]={1,-1,0,0};
int y[8]={0,0,-1,1};
void bfs()
{
     long i,a,b,c,d;
     while(!q1.empty())
     {
       a=q1.front();b=q2.front();
       q1.pop();q2.pop();
       for(i=0;i<4;i++)
       {
         c=a+x[i];d=b+y[i];
         if(c>=0&&d>=0&&c<n&&d<n&&(grid[c][d]=='@'||grid[c][d]=='x')&&!vis[c][d])
         {
             q1.push(c);q2.push(d);
             vis[c][d]=1;
         }
       }
     }
}
int main()
{
    long kase,i,j,cnt,kas=1;
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld",&n);
      getchar();
      for(i=0;i<n;i++)
        gets(grid[i]);
      cnt=0;
      memset(vis,0,sizeof(vis));
      for(i=0;i<n;i++)
       for(j=0;j<n;j++)
        if(grid[i][j]=='x'&&!vis[i][j])
        {q1.push(i);q2.push(j);vis[i][j]=1;cnt++;bfs();}  
       printf("Case %ld: %ld\n",kas++,cnt);    
    }
    return 0;
}
