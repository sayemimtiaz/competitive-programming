#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;

int n;
int grid[120][120];
bool vis[120][120];

bool parse(char *,int);
inline int color(int,int,int);
bool dfs(int,int,int);

int main()
{
    char str[10000];
    int i,j;
    bool flag;
    while(scanf("%d",&n)&&n)
    {
      memset(grid,0,sizeof(grid));
      getchar();flag=1;
      for(i=1;i<n;i++)
      {
        gets(str);
        if(!flag)
        continue;
        flag=parse(str,i);
        //printf("Returned %d\n",flag);
      }
      if(flag)
      {
       for(i=1;flag&&i<=n;i++)
        for(j=1;flag&&j<=n;j++)
          if(grid[i][j]==0&&vis[i][j]==0)
           { flag=dfs(i,j,0);break;}
      }
      if(!flag)
       printf("wrong\n");
      else
       printf("good\n");
      memset(vis,0,sizeof(vis));
    }
    return 0;
}

bool parse(char *str,int c)
{
  char *pch;
  int cnt=0,a,b;
  if(str[0]=='\0')
   return 0;
  pch=strtok(str," ");
  sscanf(pch,"%d",&a);
  pch=strtok(NULL," ");
  sscanf(pch,"%d",&b);
  cnt+=color(a,b,c);
  while((pch=strtok(NULL," "))!=NULL)
  {
    sscanf(pch,"%d",&a);
    pch=strtok(NULL," ");
    //if(pch==NULL)
    // return 0;
    sscanf(pch,"%d",&b);
    cnt+=color(a,b,c);
  }
 // printf("Parsed %d a=%d b=%d\n",cnt,a,b);
  return (cnt==n)?dfs(a,b,c):0;
}

inline int color(int a,int b,int c)
{
  // if(a<1||b<1||a>n||b>n)
   // return 0;
   if(grid[a][b]==c)
    return 0;
   grid[a][b]=c;
   return 1;
}

bool dfs(int a,int b,int c)
{
     int x[4]={0,0,1,-1};
     int y[4]={1,-1,0,0};
     stack<int>q1,q2;
     int cc,dd,i;
     q1.push(a);
     q2.push(b);
     vis[a][b]=1;
     int cnt=0;
     while(!q1.empty())
     {
       a=q1.top();q1.pop();
       b=q2.top();q2.pop();
       cnt++;
     // printf("C%d %d\n",a,b);
       for(i=0;i<4;i++)
       {
         cc=a+x[i];
         dd=b+y[i];
         if(cc<1||dd<1||cc>n||dd>n||vis[cc][dd]||grid[cc][dd]!=c)
          continue;
       //  printf("%d %d\n",cc,dd);
         q1.push(cc);
         q2.push(dd);
         vis[cc][dd]=1;
       }
     }
    // printf("DFS counted %d\n",cnt);
     return (cnt==n);
}
