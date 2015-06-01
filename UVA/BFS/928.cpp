#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#define MIN(a,b) (a>b)?b:a
using namespace std;
queue<long>q1,q2,q3;

long R,C,a,b,c,d;
char grid[310][310];
bool vis[310][310][4];
long dis[310][310][4];

int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};

bool check(int i)
{
  int j;
  switch(i)
  {
    case 0:
        for(j=b+1;j<=d;j++)
         if(grid[a][j]=='#')
          return 0;
         return 1;
    case 1: 
       for(j=b-1;j>=d;j--)
         if(grid[a][j]=='#')
          return 0;
         return 1;
    case 2:
        for(j=a+1;j<=c;j++)
         if(grid[j][b]=='#')
          return 0;
         return 1;
    case 3: 
       for(j=a-1;j>=c;j--)
         if(grid[j][b]=='#')
          return 0;
         return 1;
  }
}
void bfs()
{
  long i,m,nm;
  while(!q1.empty())
  {
    a=q1.front();q1.pop();
    b=q2.front();q2.pop();
    m=q3.front();q3.pop();
    if(m==0||m==3)
    {
     nm=1;
    for(i=0;i<4;i++)
    {
      c=a+x[i];
      d=b+y[i];
      if(c<0||d<0||c>=R||d>=C||grid[c][d]=='#'||vis[c][d][nm])
       continue;
       vis[c][d][nm]=1;
       dis[c][d][nm]=dis[a][b][m]+1;
       q1.push(c);q2.push(d);q3.push(nm);
    }
    }
    else if(m==1)
    {
     nm=2;
     for(i=0;i<4;i++)
    {
      c=a+(nm*x[i]);
      d=b+(nm*y[i]);
      if(c<0||d<0||c>=R||d>=C||grid[c][d]=='#'||vis[c][d][nm]||!check(i))
       continue;
       vis[c][d][nm]=1;
       dis[c][d][nm]=dis[a][b][m]+1;
       q1.push(c);q2.push(d);q3.push(nm);
    }
    }
    else
     {
     nm=3;
     for(i=0;i<4;i++)
    {
      c=a+(nm*x[i]);
      d=b+(nm*y[i]);
      if(c<0||d<0||c>=R||d>=C||grid[c][d]=='#'||vis[c][d][nm]||!check(i))
       continue;
       vis[c][d][nm]=1;
       dis[c][d][nm]=dis[a][b][m]+1;
       q1.push(c);q2.push(d);q3.push(nm);
    }  
  }
}
}
int main()
{
    long kase,i,j,ei,ej,res;
  scanf("%ld",&kase);
  while(kase--)
  {
    scanf("%ld %ld",&R,&C);
    for(i=0;i<R;i++)
    {
      getchar();
      for(j=0;j<C;j++)
      {
        scanf("%c",&grid[i][j]);
        if(grid[i][j]=='S')
        {dis[i][j][0]=0;q1.push(i);q2.push(j);q3.push(0);vis[i][j][0]=1;}
        else if(grid[i][j]=='E')
        {ei=i;ej=j;}
      }
    }
    bfs();
    res=2147483647;
    for(i=1;i<=3;i++)
     if(vis[ei][ej][i])
      res=MIN(res,dis[ei][ej][i]);
    if(res!=2147483647)
    printf("%ld\n",res);
    else
     printf("NO\n");
     memset(vis,0,sizeof(vis));
  }
  return 0;
} 
