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
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,0,sizeof(x))
#define swap(a,b,t) t=a,a=b,b=t
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
typedef pair<int,int>pii;


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


int main()
{
    int x[100],i,n,kas=0,b,e,q,m;
    char temp[1000],str[1000],tmp[1000];
    
    while(S1(n)&&n)
    {
      rep(i,0,n-1){
        getchar();
       scanf("%*c%d",&m);
       x[m-1]=i;
       }
       scanf("%s",str);
       S1(q);
       printf("S-Tree #%d:\n",++kas);
       while(q--){
        scanf("%s",tmp);
        rep(i,0,n-1)
         temp[x[i]]=tmp[i];
         temp[n]='\0';
        b=1;e=(1<<n);
        rep(i,0,n-1){
          m=(b+e)/2;
         if(temp[i]=='1') b=m+1;
         else e=m;
         }
         printf("%c",str[b-1]);
         }
         printf("\n\n");
    }
    return 0;
}
