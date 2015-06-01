#include<cstdio>
#include<stack>
using namespace std;
stack<int>s1,s2;
bool vis[20][20],white,black;
char grid[20][20];
int dfs(int a,int b)
{
     int x[4]={0,0,1,-1};
     int y[4]={1,-1,0,0};
     int c,d,i,cnt;
     s1.push(a);s2.push(b);
     vis[a][b]=1;
     white=black=0;cnt=0;
     while(!s1.empty())
     {
       a=s1.top();b=s2.top();
       s1.pop();s2.pop();
       cnt++;
       for(i=0;i<4;i++)
       {
          c=a+x[i];
          d=b+y[i];
          if(c<1||d<1||c>9||d>9)
           continue;
          if(vis[c][d])
          {
           if(grid[c][d]=='X')
            black=1;
           else if(grid[c][d]=='O')
            white=1;
           continue;
          }
          s1.push(c);
          s2.push(d);
          vis[c][d]=1;
       }
     }
     if(white&&black)
      return 0;
     return cnt;
}
int main()
{
    int i,j,kase,W,B,K;
    scanf("%d",&kase);
   getchar();
    while(kase--)
    {
       W=B=0;
       for(i=1;i<=9;i++)
       {
         for(j=1;j<=9;j++)
         { 
            scanf("%c",&grid[i][j]);
            if(grid[i][j]=='.')
             vis[i][j]=0;
            else if(grid[i][j]=='X')
            {
             B++;
             vis[i][j]=1;
             }
            else
            {
             W++;
             vis[i][j]=1;
             }
         }
        getchar();
       }
        for(i=1;i<=9;i++)
         for(j=1;j<=9;j++)
         {
            if(!vis[i][j])
            {
              K=dfs(i,j);
              if(white)
               W+=K;
              else
               B+=K;
            }
         }
        printf("Black %d White %d\n",B,W);
    }
    return 0;
}
