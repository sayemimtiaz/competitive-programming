#include<iostream>
#include<queue>
#include<cstring>
#define unchar(c) ((c)-'A')
using namespace std;
queue <long>q1,q2,q4;
queue<char>q3;
long N;
char G[30][30],dest;
bool vis[12][12][27]; 
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
#define  mod 20437
void bfs(long si,long sj)
{
     memset(vis,0,sizeof(vis));
     q1.push(si);q2.push(sj);q3.push('A');q4.push(0);
     long a,b,i,c,d,w,m;
     char l,ch;
     while(!q1.empty())
     {
       a=q1.front();q1.pop();
       b=q2.front();q2.pop();
       l=q3.front();q3.pop();
       w=q4.front();q4.pop();
       if(vis[a][b][unchar(l)])
        continue;
       vis[a][b][unchar(l)]=1;
       if(G[a][b]==dest)
       {
         cout << w << endl;
         while(!q1.empty())
         {
           q1.pop();q2.pop();q3.pop();q4.pop();
         }
         return;
       }
       if(G[a][b]==l)
        G[a][b]='.',l++;
       for(i=0;i<4;i++)
       {
         c=a+x[i];
         d=b+y[i];
         if(c<0||d<0||c>=N||d>=N||vis[c][d][unchar(l)]||G[c][d]=='#')
          continue;
         if(G[c][d]=='.'||G[c][d]==l)
         {
            q1.push(c);q2.push(d);
            q3.push(l);q4.push(w+1);
         }
       }
     }
     cout << "Impossible" << endl;
}
int main()
{
    long kase,i,j,ei,ej,kas=0,si,sj,r;
    cin>>kase;
    while(kase--)
    {
      cin>>N;
       dest='A';
       for(i=0;i<N;i++)
       {
           for(j=0;j<N;j++)
           {
             cin>>G[i][j];
             if(G[i][j]=='A')
             si=i,sj=j;
             if(G[i][j]>='A'&&G[i][j]<='Z'&&dest<G[i][j])
             dest=G[i][j];
           }
       } 
       cout<<"Case "<<++kas<<": ";
       bfs(si,sj);
    }
    return 0;
}
