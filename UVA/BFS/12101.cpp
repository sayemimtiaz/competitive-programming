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
#define eps 0.00000000001

struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

qi q;
int a[5000],c;
bool prime[10009];
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
inline bool check(int a,int b)
{
  int cnt=0;
  while(a)
  {
    if(a%10!=b%10)
     cnt++;
    a/=10;
    b/=10;
  }
  return (cnt==1);
}
void sieve(int N)
{
     int i,j;
     int M=sqrt(N);
	c=0;
	for(i=3;i<=N;i+=2)
		if(!prime[i])
		{        
            if(i>999)
            a[c++]=i;
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
}
int main()
{
    int kase,F,T,d[10009],u,i;
    sieve(10002);
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&F,&T);
      bool vis[10009]={0};
      q.push(F);
      d[F]=0;
      vis[F]=1;
      while(!q.empty())
      {
        u=q.front();
        q.pop();
        for(i=0;i<c;i++)
        {
         if(!vis[a[i]])
          if(check(u,a[i]))
          d[a[i]]=d[u]+1,q.push(a[i]),vis[a[i]]=1;
        }
      }
      if(vis[T])
       printf("%d\n",d[T]);
      else
       printf("Impossible\n");
    }
    return 0;
}
