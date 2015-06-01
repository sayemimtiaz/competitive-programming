#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define INF 114748364
map<string,long>list;
map<long,string>pp;
long N,p[120][120],q[120][120];
void path(long s,long d)
{
  if(p[s][d]==s)
   return;
  path(s,p[s][d]);
  cout<<" "<<pp[p[s][d]];
}
int main()
{
    long i,j,kase,k,s,d,h;
    string str,o1,o2,o3;
    cin>>kase;
    while(kase--)
    {
       cin>>N;
       for(i=0;i<N;i++)
        {cin>>str;
        pp[i]=str;
        list[str]=i;
        }
       for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
         cin>>q[i][j];
         if(q[i][j]==-1)
          q[i][j]=INF;
          p[i][j]=i;
        }
       for(i=0;i<N;i++)
        for(j=0;j<N;j++)
         for(k=0;k<N;k++)
          if(q[j][k]>(q[j][i]+q[i][k]))
          {
           q[j][k]=(q[j][i]+q[i][k]);
           p[j][k]=p[i][k];
           }
        cin>>h;
        while(h--)
        {
        cin>>o1>>o2>>o3;
       s=list[o2];
       d=list[o3];
       if(q[s][d]==INF)
        cout<<"Sorry Mr "<<o1<<" you can not go from "<<o2<<" to "<<o3<<"\n";
       else
       {
           cout<<"Mr "<<o1<<" to go from "<<o2<<" to "<<o3<<", you will receive "<<q[s][d]<<" euros\n";
           cout<<"Path:"<<o2;
           path(s,d);
           cout<<" "<<o3<<"\n";
       }
    }
        
    }
    return 0;
}
