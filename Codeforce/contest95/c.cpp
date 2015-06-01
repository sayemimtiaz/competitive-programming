#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
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

#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64  long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,0,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
#define swap(a,b,t) t=a,a=b,b=t

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
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
}

i64 nCr(i64 n,i64 r)
{
  i64 a[10]={2,3,5,7,11,13,17,19,23,29};
  i64 aa,d,i,j,temp,ans,res,F[35]={0};
  rep(i,2,n)
  {
     aa=i;
    for(j=0;a[j]<=aa&&j<10;)
    {
      if(aa%a[j]==0){
       aa/=a[j];
       F[a[j]]++;
   //    cout<<a[j]<<" "<<F[a]
       }
       else
        j++;
    }
  }
  rep(i,2,r)
  {
     aa=i;
    for(j=0;a[j]<=aa&&j<10;)
    {
      if(aa%a[j]==0){
       aa/=a[j];
       F[a[j]]--;
       }
       else
        j++;
    }
  }
  d=n-r;
   rep(i,2,d)
  {
     aa=i;
    for(j=0;a[j]<=aa&&j<10;)
    {
      if(aa%a[j]==0){
       aa/=a[j];
       F[a[j]]--;
       }
       else
        j++;
    }
  }
  ans=1;
  rep(i,0,9){
  // cout<<a[i]<<" "<<F[i]<<endl;
   rep(j,1,F[a[i]])
    ans*=a[i];
}
  return ans;
}
int main()
{
    i64 m,n,t,a,b,ans=0;
    cin>>n>>m>>t;
    for(a=4;a<=n;a++)
    {
      if(t-a<=0||t-a>m) continue;
      ans+=(nCr(n,a)*nCr(m,t-a));
    }
     cout<<ans<<endl;
    // getchar();getchar();
    return 0;
}
