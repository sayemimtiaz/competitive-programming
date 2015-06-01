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
#define i64 int
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,0,sizeof(x))
#define swap(a,b) a^=b,b^=a,a^=b
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



inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b) {return (a>b)?b:a;}
inline dle dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
bool T[1005][1005];
int M[1005],n;

int dp(int c)
{
  if(c>n) return 0;
  int &ret=M[c];
  if(ret!=-1) return ret;
  ret=INT_MX;
  int i;
//  printf("Pita %d\n",c);
  rep(i,c,n)
   if(T[c][i]){
    //  printf("sontan %d\n",i+1);
    ret=MIN(ret,1+dp(i+1));
    // printf("bs %d %d\n",c,ret);
      }
   
   return M[c]=ret;
}
int main()
{
    int i,j,k,kase,kas=0;
    char str[1200];
    
    S1(kase);
    while(kase--)
    {
     scanf("%s",str);
     n=strlen(str);
    
     rep(i,1,n){
      T[i][i]=1;
      M[i]=-1;
      }
      M[0]=-1;
      
     for(i=2;i<=n;i++)
      for(k=i,j=1;j<=n-i+1;k++,j++)
       if(str[j-1]==str[k-1]&&(k-j==1||T[j+1][k-1])){
        T[j][k]=1;
        //printf("T[%d][%d]=%d\n",j,k,T[j][k]);
        }
      
        printf("Case %d: %d\n",++kas,dp(1));
        mems(T);
       
    }
    return 0;
}
