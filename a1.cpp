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
  return a;
}
char T[1000999];
int F[1000999];

int main()
{
    i64 i,j,k,A,ans,s;
    
      gets(T);
        ans=0;
        if(T[0]=='0'||T[0]=='8') ans++;
        if(T[0]!='0')F[0]=1;
        if(T[1]=='0'||T[1]=='8') ans++;
        if(T[1]!='0')F[1]=F[0]+1;
        else F[1]=F[0];
        if(T[1]!='\0'){
         A=(10*(T[0]-'0'))+(T[1]-'0');
         if(A&&A%8==0) ans++;
         }
        for(i=2;T[i]!='\0';i++)
        {
          if(T[i]=='0'||T[i]=='8') ans++;
          if(T[i]!='0')F[i]=F[i-1]+1;
          else F[i]=F[i-1];
         A=(10*(T[i-1]-'0'))+(T[i]-'0');
         if(A&&A%8==0) ans++;
         A=(100*(T[i-2]-'0'))+A;
         if(A%8==0)
          ans+=(F[i-2]);    
        }
        printf("%lld\n",ans);
        mems(F);
      //  getchar();
        
    return 0;
}
