#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef queue<long>qi;
qi q1,q2,q3,q4;
bool vis[11][11][11][11];
long di[11][11][11][11];
void bfs()
{
     long a,b,c,d,aa;
     while(!q1.empty())
     {
       a=q1.front();b=q2.front();c=q3.front();d=q4.front();
       q1.pop();q2.pop();q3.pop();q4.pop();
       aa=a+1;if(aa>9)aa=0;
       if(!vis[aa][b][c][d])
       {
          vis[aa][b][c][d]=1;
         di[aa][b][c][d]=di[a][b][c][d]+1;
          q1.push(aa);q2.push(b);q3.push(c);q4.push(d);
       }
       aa=b+1;if(aa>9)aa=0;
       if(!vis[a][aa][c][d])
       {
          vis[a][aa][c][d]=1;
         di[a][aa][c][d]=di[a][b][c][d]+1;
          q1.push(a);q2.push(aa);q3.push(c);q4.push(d);
       }
        aa=c+1;if(aa>9)aa=0;
       if(!vis[a][b][aa][d])
       {
          vis[a][b][aa][d]=1;
        di[a][b][aa][d]=di[a][b][c][d]+1;
          q1.push(a);q2.push(b);q3.push(aa);q4.push(d);
       }
       aa=d+1;if(aa>9)aa=0;
       if(!vis[a][b][c][aa])
       {
          vis[a][b][c][aa]=1;
          di[a][b][c][aa]=di[a][b][c][d]+1;
          q1.push(a);q2.push(b);q3.push(c);q4.push(aa);
       }
       aa=d-1;if(aa<0)aa=9;
       if(!vis[a][b][c][aa])
       {
          vis[a][b][c][aa]=1;
          di[a][b][c][aa]=di[a][b][c][d]+1;
          q1.push(a);q2.push(b);q3.push(c);q4.push(aa);
       }
       aa=c-1;if(aa<0)aa=9;
       if(!vis[a][b][aa][d])
       {
          vis[a][b][aa][d]=1;
         di[a][b][aa][d]=di[a][b][c][d]+1;
          q1.push(a);q2.push(b);q3.push(aa);q4.push(d);
       }
       aa=a-1;if(aa<0)aa=9;
       if(!vis[aa][b][c][d])
       {
          vis[aa][b][c][d]=1;
          di[aa][b][c][d]=di[a][b][c][d]+1;
          q1.push(aa);q2.push(b);q3.push(c);q4.push(d);
       }
       aa=b-1;if(aa<0)aa=9;
       if(!vis[a][aa][c][d])
       {
          vis[a][aa][c][d]=1;
          di[a][aa][c][d]=di[a][b][c][d]+1;
          q1.push(a);q2.push(aa);q3.push(c);q4.push(d);
       }
     }
}
int main()
{
    long sa,sb,sc,sd,ea,eb,ec,ed,a,b,c,d,kase,nd,j;
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld %ld %ld %ld",&sa,&sb,&sc,&sd);
      q1.push(sa);q2.push(sb);q3.push(sc);q4.push(sd);
      vis[sa][sb][sc][sd]=1; 
      scanf("%ld %ld %ld %ld",&ea,&eb,&ec,&ed);
      scanf("%ld",&nd);
      while(nd--)
      {
        scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
        vis[a][b][c][d]=1;
      }
       bfs();
       if(sa==ea&&sb==eb&&sc==ec&&sd==ed)
        printf("0\n");
      else if(di[ea][eb][ec][ed])
        printf("%ld\n",di[ea][eb][ec][ed]);
      else 
        printf("-1\n");
      memset(vis,0,sizeof(vis));
     memset(di,0,sizeof(di));
    }
    return 0;
}
