#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<int>s1,s2;
int M,N;
bool vis[50][50];
char grid[50][50];
int dfs(int a,int b)
{
     int x[8]={0,0,1,-1,1,-1,1,-1};
     int y[8]={1,-1,0,0,1,-1,-1,1};
     int c,d,i,cnt=0;
     s1.push(a);s2.push(b);
     vis[a][b]=1;
     cnt=0;
     while(!s1.empty())
     {
       a=s1.top();b=s2.top();
       s1.pop();s2.pop();
       cnt++;
       for(i=0;i<8;i++)
       {
          c=a+x[i];
          d=b+y[i];
          if(c<0||d<0||c>=M||d>=N||vis[c][d]||grid[c][d]=='0')
           continue;
          s1.push(c);
          s2.push(d);
          vis[c][d]=1;
       }
     }
     return cnt;
}
int main()
{
    bool flag=0;
    int i,j,max,K,kase;
    scanf("%d",&kase);
    getchar();
    getchar();
    while(kase--)
    {
       i=0;
       while(gets(grid[i])&&grid[i][0]!='\0')
         i++;
       N=strlen(grid[0]);
       M=i;
       max=0;
        for(i=0;i<M;i++)
         for(j=0;j<N;j++)
            if(!vis[i][j]&&grid[i][j]=='1')
              K=dfs(i,j), max=(max<K)?K:max;
        if(flag)
         printf("\n");
        flag=1;
        printf("%d\n",max);
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
