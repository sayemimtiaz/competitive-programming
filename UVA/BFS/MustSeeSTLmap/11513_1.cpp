#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std; 

struct state
{
      int s[3][3];
};

void bfs();
int encode(state &);
void decode(int,state &);

queue<int>q; 
map<int,int>par;
map<int,string>type;

int main()
{
    int i;
    bfs();
    int x=0,u;
    while(cin>>u&&u)
    {
      x=0;
      for(i=0;i<9;i++)
      {
        if(i)cin>>u;
        x=(x*10)+u;
      }
      if(!x)
       break;
      if(!par.count(x))
       cout<<"Not solvable"<<endl;
      else
      {
        string s="";
        while(par[x]!=-1)
        {
         s+=type[x];
         x=par[x];
        }
        cout<<s.size()/2<<" "<<s<<endl;
      }
    }
    return 0;
}

int encode(state &s)
{
    int i,j,r=0;
    for(i=0;i<3;i++)
     for(j=0;j<3;j++)
      r=(r*10)+s.s[i][j];
     return r;
}
void decode(int x,state &s)
{
     int i,j;
     for(i=2;i>=0;i--)
      for(j=2;j>=0;j--)
       s.s[i][j]=x%10,x/=10;
}

void bfs()
{
  state u,v;
  int x,i,temp;
  par[123456789]=-1;
  q.push(123456789);
  while(!q.empty())
  {
      x=q.front();q.pop();
      decode(x,u);
     for(i=0;i<3;i++)
     {
       v=u;
       temp=v.s[i][0],v.s[i][0]=v.s[i][1],v.s[i][1]=v.s[i][2],v.s[i][2]=temp;
       temp=encode(v);
       if(!par.count(temp))
         q.push(temp),par[temp]=x,type[temp]=string("H")+char(i+'1');
     }
     for(i=0;i<3;i++)
     {
       v=u;
        temp = v.s[2][i], v.s[2][i] = v.s[1][i], v.s[1][i] = v.s[0][i], v.s[0][i] = temp;
       temp=encode(v);
       if(!par.count(temp))
         q.push(temp),par[temp]=x,type[temp]=string("V")+char(i+'1');
     }
  }     
}
