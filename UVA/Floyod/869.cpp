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
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
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
}

void floyd(int C[27][27])
{
  int i,k,j;
  rep(k,0,25)
   rep(i,0,25)
    rep(j,0,25)
     C[i][j]=C[i][j]|(C[i][k]&C[k][j]);
}
int main()
{
    char a,b;
    int i,j,n,kase,c,d;
    bool flag,got=0;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
       getchar();
      int C1[27][27]={0};
      int C2[27][27]={0};
      scanf("%d",&n);
      while(n--){
         getchar();
         scanf("%c %c",&a,&b);
         a=tolower(a)-'a';b=tolower(b)-'a';
         C1[a][b]=C1[b][a]=1;
         }
      scanf("%d",&n);
      while(n--){
         getchar();
         scanf("%c %c",&a,&b);
            a=tolower(a)-'a';b=tolower(b)-'a';
         C2[a][b]=C2[b][a]=1;
         }
      floyd(C1);
      floyd(C2);
      flag=1;
      rep(i,0,25)
       rep(j,0,25)
        if(C1[i][j]!=C2[i][j]){
          flag=0;
          break;
          }
          if(got)
           printf("\n");
           got=1;
        if(flag)
         printf("YES\n");
        else
         printf("NO\n");
    }
    return 0;
}
