#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define INF 2147483647
queue <long> q;
long grid[10][10];
bool wall[8][8][8][8];
char way[10][10];
void bfs()
{
   long a,b;
   while(!q.empty())
   {
     a=q.front();q.pop();
     b=q.front();q.pop();
     if((a-1)>0&&!wall[a-1][b-1][a-1][b]&&grid[a-1][b]>grid[a][b]+1)
     {
        grid[a-1][b]=grid[a][b]+1;
        way[a-1][b]='S';
        q.push(a-1);q.push(b);
     }
     if((a+1)<=6&&!wall[a][b-1][a][b]&&grid[a+1][b]>grid[a][b]+1)
     {
        grid[a+1][b]=grid[a][b]+1;
        way[a+1][b]='N';
        q.push(a+1);q.push(b);
     }
     if((b-1)>0&&!wall[a-1][b-1][a][b-1]&&grid[a][b-1]>grid[a][b]+1)
     {
        grid[a][b-1]=grid[a][b]+1;
        way[a][b-1]='E';
        q.push(a);q.push(b-1);
     }
     if((b+1)<=6&&!wall[a-1][b][a][b]&&grid[a][b+1]>grid[a][b]+1)
     {
        grid[a][b+1]=grid[a][b]+1;
        way[a][b+1]='W';
        q.push(a);q.push(b+1);
     }
                                           
   }
}
void print(long x,long y)
{
     if(way[x][y]=='-')
      return;
     if(way[x][y]=='N')
     {
       print(x-1,y);
       printf("S");
     }
     else if(way[x][y]=='S')
     {
       print(x+1,y);
       printf("N");
     }
     else if(way[x][y]=='W')
     {
       print(x,y-1);
       printf("E");
     }
     else
     {
       print(x,y+1);
       printf("W");
     }
}
int main()
{
    long x,y,i,j,a,b,c,d;
    while(scanf("%ld %ld",&y,&x)==2&&(x||y))
    {
      for(i=0;i<=6;i++)
       for(j=0;j<=6;j++)
        grid[i][j]=INF;
      grid[x][y]=0;
      way[x][y]='-';
      q.push(x);q.push(y);
      scanf("%ld %ld",&y,&x);
      for(i=0;i<3;i++)
      {
        scanf("%ld %ld %ld %ld",&b,&a,&d,&c);
        if(a==c)
        {
          for(j=b+1;j<=d;j++)
            wall[a][j-1][c][j]=1;
        }
        else
        {
            for(j=a+1;j<=c;j++)
              wall[j-1][b][j][d]=1;
        }
      }
      bfs();
      print(x,y);
      printf("\n");
      memset(wall,0,sizeof(wall));
    }
    return 0;
}
