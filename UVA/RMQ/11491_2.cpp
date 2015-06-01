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

int a[SIZE],s[SIZE],m[SIZE];
char num[SIZE];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
void initialize(int node,int b,int e)
{
  if(b==e)
   m[node]=a[b],s[node]=b;
  else
  {
      initialize(2*node,b,(b+e)/2);
      initialize(2*node+1,(b+e)/2+1,e);
      if(m[2*node]<=m[2*node+1])
       m[node]=m[2*node],s[node]=s[2*node];
      else
       m[node]=m[2*node+1],s[node]=2*node+1;
  }
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)
     return -1;
    
    if(i<=b&&j>=e){x=s[node];
     return m[node];}
    int p1=query(2*node,b,(b+e)/2,i,j);
    int p2=query(2*node+1,(b+e)/2+1,e,i,j);
    if(p1==-1)
     return p2;
    if(p2==-1)
     return p1;
    if(p1<p2)
     return p1;
    return p2;   
}


int main()
{
    int n,i,j,b,max,q,c,g,x,y,mm,index;
    while(scanf("%d %d",&n,&mm)&&(n||mm))
    {
     scanf("%s",&num);
    for(i=0;i<n;i++)
     a[i]=num[i]-'0';
    initialize(1,0,n-1);
    
    x=0;mm=n-mm;
    for(j=mm;j>0;j--)
    {
      y=n-j;
      printf("%d",max);
      x=index;
    }
    printf("\n");
    }
    return 0;
}
