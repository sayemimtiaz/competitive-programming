#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<cctype>
#include<string>
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 611999
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
const int mod=611957;

vector<string>P[SIZE];
vector<int>cn[SIZE];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

i64 npow(int n,int p)
{
    if(p==1)
     return n;
    if(p==0)
     return 1;
    i64 a;
    a=npow(n,p/2);
    a=(a*a)%mod;
    if(p%2)
     a=(a*n)%mod;
    return a; 
}

int main()
{
    string T;
    char ch[100],str[100];
    int i,n,m,s,d,k,j,max,mt,mj;
    i64 a,pp,t;
    bool found,flag;
    while(cin>>m>>T)
    {
      //Radix
       d=29;
      t=0;
      //Preprocessing
      for(i=0;i<m;i++)
        t=(((d*t)%mod)+(T[i]%d))%mod;
        
      n=T.length();
      //log(n) method to compute pow()
      pp=npow(d,m-1)%mod;
      max=0;
      for(s=0;s<=(n-m);s++)
      {
          flag=false;
          for(j=P[t].size()-1;j>=0;j--){
          for(i=0;i<m;i++)
           if(T[s+i]!=P[t][j][i])
            break;
          if(i==m)
          {flag=true;
          cn[t][j]++;
          if(cn[t][j]>max)
          {
            max=cn[t][j];
            mt=t;mj=j;
          }
          break;}
          }
          if(flag==false)
          {
             for(i=0;i<m;i++)
              ch[i]=T[s+i];
             ch[i]='\0';
             P[t].push_back(ch);
             cn[t].push_back(1);
          if(!max)
           {
            max=1;
            mt=t;mj=0;
           }
          }
        if(s<(n-m))
        {
         a=(d*(t-((pp*(T[s]%d))%mod))%mod);
         if(a<0)
          a+=mod;
         t=(a+(T[s+m]%d))%mod;
         
        }
      }
      cout<<P[mt][mj]<<endl;
      for(i=0;i<=SIZE;i++)
       P[i].clear(),cn[i].clear();
      }
      return 0;
}
