#include<string>
#include<map>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

map<string,int>m1;
map<int,string>m2;
vector<int>adj[120];

bool cmp(int a,int b)
{
     return (m1[m2[a]]<m1[m2[b]]);
}

int main()
{
    string s1,s2;
    int kas=1,N,M,a,b,i,j,k,q[120],rear,front,next,in[120];
    while(cin>>N)
    {
      for(i=0;i<N;i++)
       cin>>s1,m1[s1]=i,m2[i]=s1;
      cin>>M;
      memset(in,0,sizeof(in));
      for(i=1;i<=M;i++)
      {
       cin>>s1>>s2;
       a=m1[s1],b=m1[s2];
       adj[a].push_back(b);
       in[b]++;
       }
       rear=0;
       for(i=0;i<N;i++)
         if(!in[i])
          q[rear++]=i;
       cout<<"Case #"<<kas++<<": Dilbert should drink beverages in this order:";
       front=0;
       while(front<rear)
       {
           sort(q+front,q+rear,cmp);
           cout<<" "<<m2[q[front]];
           for(j=adj[q[front]].size()-1;j>=0;j--)
           {
             next=adj[q[front]][j];
             if(in[next]>0)
             {
             in[next]--;
             if(in[next]==0)
              q[rear++]=next;
             }
           }
           front++;
       }
       cout<<".\n\n";
       for(i=0;i<N;i++)
         adj[i].clear();
       m1.clear();m2.clear();
    }
    return 0;
}
