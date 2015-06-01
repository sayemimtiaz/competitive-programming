#include<iostream>
#include<string>
#include<map>
using namespace std;
#define MAXN 40
double Q[MAXN][MAXN];
int main()
{
    long N,i,j,k,kas=1,E;
    double tmp;
    string str,str1;
    map<string,int>m;
    while(cin>>N&&N)
    {
      for(i=1;i<=N;i++)
      {
         cin>>str;
         m[str]=i;
      }
      cin>>E;
      for(i=1;i<=N;i++)
          Q[i][i]=1;
       for(i=1;i<=E;i++)
       {
         cin>>str>>tmp>>str1;
         Q[m[str]][m[str1]]=tmp;
       }
       for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
         for(k=1;k<=N;k++)
         {
           if(Q[j][k]<(Q[j][i]*Q[i][k]))
            Q[j][k]=(Q[j][i]*Q[i][k]);
         }
         bool flag=1;
         cout<<"Case "<<kas++<<": ";
        for(i=1;flag&&i<=N;i++)
         if(Q[i][i]>1.0001)
         {
          cout<<"Yes\n";
          flag=0;
          }
         if(flag)
          cout<<"No\n";
         memset(Q,0,sizeof(Q));
    }
    return 0;
}
