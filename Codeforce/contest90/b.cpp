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
#define mem(x) memset(x,sizeof(x),0)
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

int main()
{
    double n,k,m1,m2,c,a[120],e[120],sum;
    int q,i,j,l,d;
    scanf("%lf %lf",&n,&k);
    
    bool mark[120]={0};
      c=floor(n/k);
      for(i=1;i<=n;i++)
       scanf("%lf",&a[i]);
      scanf("%d",&q);
      int aa=q;
      bool flag=0;
      
     while(q--)
     {
       sum=0.00;
       for(i=1;i<=c;i++){
        scanf("%d",&d);
        sum+=a[d];
        mark[d]=1;
        }
      
       sum/=c;
       if(!flag)
        flag=1,m1=m2=sum;
       else{
       if(m1-sum>eps)
        m1=sum;
       if(sum-m2>eps)
        m2=sum;
        }
     }
     j=0;
     for(i=1;i<=n;i++)
      if(!mark[i])
       e[j++]=a[i];
      sort(e,e+j);
      aa=(n-j)/(double)c;
      if(j&&aa<k){
      sum=0;
      for(i=0;i<c&&i<j;i++)
       sum+=e[i];
       sum/=c;
       if(!flag)
        m1=sum;
       
       else if(m1-sum>eps)
        m1=sum;
        sum=0.00;
      for(l=0,i=j-1;i>=0&&l<c;l++,i--)
       sum+=e[i];
       sum/=c;
      if(!flag)
        m2=sum;
       
       else if(sum-m2>eps)
        m2=sum;
        }
        printf("%.10lf %.10lf\n",m1,m2);
       //getchar();
       //getchar();
    return 0;
}
