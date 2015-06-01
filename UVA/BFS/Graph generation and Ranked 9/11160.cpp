#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef queue<long>q;
q q1,q2,q3;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
long m[101][101][101],n;
bool vis[101][101][101];
char str[60][60];
long bfs()
{
     long i,ax,ay,bx,by,cx,cy,sx[10],sy[10],a1,b1,c1,a,b,c;
     while(!q1.empty())
     {
       ax=q1.front();q1.pop();
       ay=q1.front();q1.pop();
       bx=q2.front();q2.pop();
       by=q2.front();q2.pop();
       cx=q3.front();q3.pop();
       cy=q3.front();q3.pop();
       a1=ax*n+ay; b1=bx*n+by; c1=cx*n+cy;
       for(i=0;i<4;i++)
       {
         sx[0]=ax+x[i];sy[0]=ay+y[i];
         if(sx[0]<0||sy[0]<0||sx[0]>=n||sy[0]>=n||str[sx[0]][sy[0]]=='#')
          {sx[0]=ax;sy[0]=ay;}
          sx[1]=bx+x[i];sy[1]=by+y[i];
          if(sx[1]<0||sy[1]<0||sx[1]>=n||sy[1]>=n||str[sx[1]][sy[1]]=='#')
          {sx[1]=bx;sy[1]=by;}
          sx[2]=cx+x[i];sy[2]=cy+y[i];
          if(sx[2]<0||sy[2]<0||sx[2]>=n||sy[2]>=n||str[sx[2]][sy[2]]=='#')
          {sx[2]=cx;sy[2]=cy;}
          if(sx[0]==sx[1]&&sy[0]==sy[1])
          {sx[0]=ax;sy[0]=ay;sx[1]=bx;sy[1]=by;
           if((sx[0]==sx[2]&&sy[0]==sy[2])||(sx[1]==sx[2]&&sy[1]==sy[2]))
           {sx[2]=cx;sy[2]=cy;}
         }
          else if(sx[0]==sx[2]&&sy[0]==sy[2])
          {sx[0]=ax;sy[0]=ay;sx[2]=cx;sy[2]=cy;
          if((sx[0]==sx[1]&&sy[0]==sy[1])||(sx[1]==sx[2]&&sy[1]==sy[2]))
           {sx[1]=bx;sy[1]=by;}
          }
          else if(sx[2]==sx[1]&&sy[2]==sy[1])
          {sx[2]=cx;sy[2]=cy;sx[1]=bx;sy[1]=by;
          if((sx[0]==sx[2]&&sy[0]==sy[2])||(sx[1]==sx[0]&&sy[1]==sy[0]))
           {sx[0]=ax;sy[0]=ay;}
          }
          a=sx[0]*n+sy[0]; b=sx[1]*n+sy[1]; c=sx[2]*n+sy[2];
         if(!vis[a][b][c])
         {
           vis[a][b][c]=vis[a][c][b]=vis[b][a][c]=vis[b][c][a]=vis[c][a][b]=vis[c][b][a]=1;
           m[a][b][c]=m[a][c][b]=m[b][a][c]=m[b][c][a]=m[c][a][b]=m[c][b][a]=m[a1][b1][c1]+1;;
           if(str[sx[0]][sy[0]]=='X'&&str[sx[1]][sy[1]]=='X'&&str[sx[2]][sy[2]]=='X')
           {
             while(!q1.empty())
              {q1.pop();q2.pop();q3.pop();}
             return m[a][b][c]; 
           }
           q1.push(sx[0]);q1.push(sy[0]);q2.push(sx[1]);q2.push(sy[1]);q3.push(sx[2]);q3.push(sy[2]);
         }
       }
     }
     return -1;
}
int main()
{
    long l,max,kase,kas=1,i,j,k,tx[10],ty[10],sx[10],sy[10],a,b,c;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld",&n);
       getchar();
       k=0;
       l=0;
       for(i=0;i<n;i++)
       {
         gets(str[i]);
         for(j=0;j<n;j++)
         {
           if(str[i][j]=='B'||str[i][j]=='A'||str[i][j]=='C')
           {sx[l]=i;sy[l]=j;l++;}
           else if(str[i][j]=='X')
           {tx[k]=i;ty[k]=j;k++;}
         }
       }
       a=sx[0]*n+sy[0]; b=sx[1]*n+sy[1]; c=sx[2]*n+sy[2];
       vis[a][b][c]=vis[a][c][b]=vis[b][a][c]=vis[b][c][a]=vis[c][a][b]=vis[c][b][a]=1;
       m[a][b][c]=m[a][c][b]=m[b][a][c]=m[b][c][a]=m[c][a][b]=m[c][b][a]=0;
       q1.push(sx[0]);q1.push(sy[0]);q2.push(sx[1]);q2.push(sy[1]);q3.push(sx[2]);q3.push(sy[2]);
       max=bfs();
       printf("Case %ld: ",kas++);
       if(max!=-1)
         printf("%ld\n",max);
        else
         printf("trapped\n");
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
