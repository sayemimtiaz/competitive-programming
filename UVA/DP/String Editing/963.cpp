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
int C[22][22],L[10001];
char x[10001][9];

inline i64 MAX(int a,int b)
{
  return (a>b)?a:b;
}
inline i64 MIN(int a,int b)
{
  return (a>b)?b:a;
}
inline dle dis(Point a,Point b)
{
  //Without sqrt()
  return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
   char y[20],str[20];
   int m1,n1,m,n,i,j,k,min,l;
   int RR;
    while(scanf("%d",&n)==1)
    {
      rep(i,0,n-1){
       scanf("%s",x[i]);
       L[i]=strlen(x[i]);
       }
      scanf("%d",&m);
      bool flag=1;
      rep(l,1,m)
      {
        scanf("%s",y);
        n1=strlen(y);
        min=INT_MX;
      rep(k,0,n-1){
       m1=L[k];
      //Insertion
      C[0][0]=0;
      rep(i,1,n1)
       C[0][i]=3+C[0][i-1];
      //Deletion
      rep(i,1,m1)
       C[i][0]=3+C[i-1][0];
       
       rep(i,1,m1)
        rep(j,1,n1){
         if(x[k][i-1]==y[j-1])RR=0;else RR=5;
         C[i][j]=MIN(3+C[i][j-1],MIN(3+C[i-1][j],RR+C[i-1][j-1]));
         }
         if(C[m1][n1]<min)
          strcpy(str,x[k]),min=C[m1][n1];
        }
        if(!flag)
         printf(" ");
        flag=0;
        printf("%s",str);
        if(l%10==0){
         printf("\n");flag=1;}
        }
        if(m%10)
         printf("\n");
    }
    return 0;
}
