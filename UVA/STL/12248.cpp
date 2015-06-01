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
vi v;

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
   map<int,int>m1,m2,m3;
   map<int,map<int,int> >m4;
int find(int a)
{
  if(a)
   m2[a]=find(m2[a]);
   if(!m2[a])
    return a;
   return m2[a];
}
int main()
{
 
    int k,w,a,b,c1,x,y,c2,u,i;
    bool flag,got;
    
    while(scanf("%d %d",&k,&w)&&(k||w))
    {
       m1.clear(); m2.clear();m3.clear();m4.clear();v.clear();
      flag=1;c1=-1;got=0;
      if(w==0){
       printf("Y\n");continue;}
      while(w--){
        scanf("%d %d",&a,&b);
        if(got||m4[a][b]) continue;
        if(!m1[a]) v.pb(a);
        if(!m1[b]) v.pb(b);
        m1[a]++;m1[b]++;
        if(m1[a]>2||m1[b]>2){ got=1;continue;}
        m4[a][b]=m4[b][a]=1;
        x=find(a),y=find(b);
        if(x==y){
          c1=x;
         flag=0;continue;}
        if(m3[x]>m3[y])
         m2[y]=x;
        else
         m2[x]=y;
         if(m3[x]==m3[y])
          m3[y]++;
        
       }
      if(got){
              printf("N\n");
       continue;}
       u=c1;c2=0;
       for(i=v.size()-1;i>=0;i--)
        if(find(v[i])==c1)
         c2++;
       if(!flag&&c2!=k)
        printf("N\n");
       else
        printf("Y\n");
           
    }
    return 0;
}
