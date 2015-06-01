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
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 unsigned long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;


inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
inline dle dis(Point a,Point b)
{
  //Without sqrt()
  return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
i64 b[3000],c;
i64 L;

i64 np(i64 n)
{
    if(n==1)
     return 10;
    if(n==0)
     return 1;
    i64 a=np(n/2);
    a=a*a;
    if(n%2)
    a*=10;
    return a;
}
void backTrack(i64 h,i64 a)
{
     
  if(h==L){
    b[c++]=a;
    return;}
  backTrack(h+1, a+(4*np(L-h-1)));
  backTrack(h+1, a+(7*np(L-h-1)));
}

int main()
{
    b[c]=0;
    c=1;
    for(L=1;L<=10;L++){
     backTrack(0,0);
     }
  //   cout<<b[c-5]<<endl;
     i64 h,l,s,e,m,ans,d;
    while(cin>>l>>h)
   {
        
       for(s=1,e=c-1;s<=e;){
          m=(s+e)/2;
          if(b[m]>=h&&b[m-1]<h)
           break;
          if(b[m]<h) s=m+1; else e=m-1;
          }
          ans=0;
         for(s=m-1,e=h;s>=0;s--){
          if(b[s]<l){
           d=e-l+1;
           ans+=(d*b[s+1]);
           break;
           }
           else
           d=e-b[s];
           ans+=(d*b[s+1]);
          // printf("%lld %lld\n",d,b[s+1]);
           e=b[s];
           }
          cout<<ans<<endl;
                   
    }
    return 0;
}
