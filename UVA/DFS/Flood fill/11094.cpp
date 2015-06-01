#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<int>s1,s2;
int M,N;
bool vis[30][30];
char grid[30][30],Land;
int dfs(int a,int b)
{
     int x[4]={0,0,1,-1};
     int y[4]={1,-1,0,0};
     int c,d,i,cnt=0;
     s1.push(a);s2.push(b);
     vis[a][b]=1;
     cnt=0;
     while(!s1.empty())
     {
       a=s1.top();b=s2.top();
       s1.pop();s2.pop();
       cnt++;
       for(i=0;i<4;i++)
       {
          c=a+x[i];
          d=b+y[i];
          if(c<0||d<0||c>=M||d>=N||vis[c][d]||grid[c][d]!=Land)
           continue;
          s1.push(c);
          s2.push(d);
          vis[c][d]=1;
       }
       if(b==0&&!vis[a][N-1]&&grid[a][N-1]==Land)
         s1.push(a),s2.push(N-1),vis[a][N-1]=1;
       else if(b==N-1&&!vis[a][0]&&grid[a][0]==Land)
           s1.push(a),s2.push(0),vis[a][0]=1;
     }
     return cnt;
}
int main()
{
    int i,j,kase,max,K,X,Y;
    while(~scanf("%d %d",&M,&N))
    {
       for(i=0;i<M;i++)
        scanf("%s",grid[i]);
       scanf("%d %d",&X,&Y);
       Land=grid[X][Y];
       dfs(X,Y);
       max=0;
        for(i=0;i<M;i++)
         for(j=0;j<N;j++)
            if(!vis[i][j]&&grid[i][j]==Land)
              K=dfs(i,j), max=(max<K)?K:max;
         
        printf("%d\n",max);
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
