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
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

 struct S
    {
      int a;
      int p;
    }s;
inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int main()
{
   
    queue<S>q;
    priority_queue<int>pq;
    
    int m,r,i,kase,n,p,a;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&p);
      for(i=0;i<n;i++)
      {
       scanf("%d",&a);
       s.a=a;s.p=i;
       q.push(s);
       pq.push(a);
       
      }
      m=1;
      while(!pq.empty())
      {
        a=pq.top();
        pq.pop();
        while(1)
        {
         s=q.front();
         q.pop();
         if(s.a==a)
          break;
         q.push(s);
        }
        if(s.p==p)
         {r=m;break;}
        m++;
      }
      printf("%d\n",r);
      while(!pq.empty())
        pq.pop();
       while(!q.empty())
        q.pop();                     
    }
    return 0;
}
