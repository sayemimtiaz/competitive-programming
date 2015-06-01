#include<iostream>
#include<map>
#include<cstring>
#include<string>
using namespace std;

bool Con[500][500];

int main()
{
    map<string,int>m1;
    map<int,string>m2;
    string Vs,Us;
    int E,C,N,i,j,k,index,pair,a[3],b[3],kas=1;
    
    while(cin>>C&&C)
    {
                        memset(Con,0,sizeof(Con));
        m1.clear();
        m2.clear();
       N=1;
       while(C--)
       {
         cin>>E;
         if(E)
          cin>>Us,m2[N]=Us,m1[Us]=N++,E--;
         while(E--)
         {
           cin>>Vs;
           m2[N]=Vs,m1[Vs]=N++;
           Con[N-2][N-1]=1;
         }
       }
       cin>>E;
       while(E--)
       {
         cin>>Us>>Vs;
         Con[m1[Us]][m1[Vs]]=1;
       }
       for(i=1;i<N;i++)
        for(j=1;j<N;j++)
          for(k=1;k<N;k++)
           Con[j][k]=Con[j][k]|(Con[j][i]&Con[i][k]);
        index=0,pair=0;
       for(i=1;i<N;i++)
        for(j=i+1;j<N;j++)
         if(!Con[i][j]&&!Con[j][i])
         {
           pair++;
           if(index==0)
           a[0]=i,b[0]=j,index=1;
           else if(index==1)
            a[1]=i,b[1]=j,index=2;
            
         }
        cout<<"Case "<<kas++<<", ";
        if(pair)
        cout<<pair<<" concurrent events:"<<endl;
        else
        {
         cout<<"no concurrent events."<<endl;
         continue;
        }
        if(index)
         cout<<"("<<m2[a[0]]<<","<<m2[b[0]]<<") ",index--;
        if(index)
        cout<<"("<<m2[a[1]]<<","<<m2[b[1]]<<") ";
        cout<<endl;
    
         
    }
    return 0;
}
