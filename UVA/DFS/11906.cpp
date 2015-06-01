#include<stdio.h>
#include<string.h>
bool vis[120][120],grid[120][120],h[120][120];
long r,c,m,n,even,odd;
void adj(long a,long b)
{
     long x,y,cnt=0;
     memset(h,0,sizeof(h));
     x=a-m;y=b-n;
     if(x>=0&&y>=0&&!grid[x][y]&&!h[x][y])
     {
       h[x][y]=1;
       cnt++;
     }
     x=a-m;y=b+n;
     if(x>=0&&y<c&&!grid[x][y]&&!h[x][y])
     {
       h[x][y]=1;cnt++;
       }
      x=a+m;y=b-n;
     if(x<r&&y>=0&&!grid[x][y]&&!h[x][y])
     {
       h[x][y]=1;
       cnt++;
       }
     x=a+m;y=b+n;
     if(x<r&&y<c&&!grid[x][y]&&!h[x][y])
     {
       h[x][y]=1;
       cnt++;
       }
      x=a-n;y=b-m;
     if(x>=0&&y>=0&&!grid[x][y]&&!h[x][y])
     {
       h[x][y]=1;
       cnt++;
       }
     x=a-n;y=b+m;
     if(x>=0&&y<c&&!grid[x][y]&&!h[x][y])
     {
       h[x][y]=1;
       cnt++;
       }
      x=a+n;y=b-m;
     if(x<r&&y>=0&&!grid[x][y]&&!h[x][y])
     {
       h[x][y]=1;
       cnt++;
       }
     x=a+n;y=b+m;
     if(x<r&&y<c&&!grid[x][y]&&!h[x][y])
     {
       h[x][y]=1;
       cnt++;
       }
    if(cnt%2==0)
      even++;
    else
      odd++;
}
void check(long a,long b)
{
     long x,y;
     adj(a,b);
     vis[a][b]=1;
      x=a-m;y=b-n;
     if(x>=0&&y>=0&&!vis[x][y])
       check(x,y);
     x=a-m;y=b+n;
     if(x>=0&&y<c&&!vis[x][y])
       check(x,y);
      x=a+m;y=b-n;
     if(x<r&&y>=0&&!vis[x][y])
       check(x,y);
     x=a+m;y=b+n;
     if(x<r&&y<c&&!vis[x][y])
       check(x,y);
      x=a-n;y=b-m;
     if(x>=0&&y>=0&&!vis[x][y])
       check(x,y);
     x=a-n;y=b+m;
     if(x>=0&&y<c&&!vis[x][y])
       check(x,y);
      x=a+n;y=b-m;
     if(x<r&&y>=0&&!vis[x][y])
       check(x,y);
     x=a+n;y=b+m;
     if(x<r&&y<c&&!vis[x][y])
       check(x,y);
     
}
int main()
{
    long kase,kas=1,w,i,j,a,b;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld %ld %ld %ld",&r,&c,&m,&n);
       scanf("%ld",&w);
       memset(grid,0,sizeof(grid));
       memset(vis,0,sizeof(vis));
       for(i=0;i<w;i++)
       {
         scanf("%ld %ld",&a,&b);          
         vis[a][b]=1;
         grid[a][b]=1;
       }
       even=odd=0;
       check(0,0);
       printf("Case %ld: %ld %ld\n",kas++,even,odd);
    }
    return 0;
}
