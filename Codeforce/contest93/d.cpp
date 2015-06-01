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

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

char str[1000009];
int F[1000009];

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

void FailureFun(char *P,int n)
{
  int i,j;
  
  F[0]=0;
  i=1,j=0;
  while(i<n){
   if(P[i]==P[j]) F[i]=j+1,i++,j++;
   else if(j>0) j=F[j-1];
   else F[i]=0,i++;
   }
}
int main()
{
    int n,m,s,i,j,k,l=0;
    while(gets(str))
    {
      n=strlen(str);
      FailureFun(str,n);
      m=F[n-1];s=0;
      if(m==0) {  printf("Just a legend\n");continue;}
      if(2*m>n) s=n-(2*(n-m));
    else{
      for(i=n-2;i>=1;i--)
       if(F[i]<=m&&s<F[i]){
       for(l=n-1,k=F[i]-1,j=i;k>=0;k--,j--,l--)
        if(str[k]!=str[j]||str[l]!=str[j])
         break;
        if(k==-1)
         s=F[i];
        }
        }
        if(!s)
         printf("Just a legend\n");
        else{
       for(k=0;k<s;k++)
        printf("%c",str[k]);
        printf("\n");
        }
    }
    return 0;
}
