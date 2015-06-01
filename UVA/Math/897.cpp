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
#define i64 unsigned
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

i64 flag[55],a[2000],c,b[55],d[9000],o,L,q[50];
i64 T[9][9][9][9];
bool vis[20];
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
i64 pwr(i64 n)
{
  if(n==0) return 1;
  if(n==1) return 10;
  i64 a=pwr(n/2);
  a=a*a;
  if(n%2) a*=10;
  return a;
}

bool IsPrime(i64 n)
{
  for(i64 i=0;a[i]<n&&i<c;i++)
   if(n%a[i]==0)
    return 0;
   return 1;
  
}
void sieve()
{
  i64 i,j,k;
  for(i=3;i<=3163;i+=2)
   if(!chkC(flag,i)){
     a[c++]=i;
     if(i<57)
      for(j=i*i,k=i<<1;j<=3163;j+=k)
       setC(flag,j);
       }
}
void gen(int h)
{
  i64 r,i,k;
  if(h==L){
    for(r=0,k=1;k<=L;k++)
      r+=(q[k-1]*pwr(L-k));
   d[o++]=r;
   return;}
   int off=-1;
   for(i=0;i<L;i++)
    {
      if(!vis[i]&&b[i]!=off){
      off=b[i];
      vis[i]=1;
      q[h]=b[i];
      gen(h+1);
      vis[i]=0;
      }
    }
}

void check()
{
  int F[]={0,1,2,6,24,120,720,5040,40320};
  i64 i,j,k,r,s;
  int fr[10]={0};
    for(r=0,k=1;k<=L;k++)
      r+=(b[k-1]*pwr(L-k)),fr[b[k-1]]++;
    s=F[L];
    if(fr[1]) s/=fr[1];
    if(fr[3]) s/=fr[3];
    if(fr[7]) s/=fr[7];
    if(fr[9]) s/=fr[9];
    if(IsPrime(r))
    T[fr[1]][fr[3]][fr[7]][fr[9]]++;
    if(T[fr[1]][fr[3]][fr[7]][fr[9]]==s)
     gen(0);

}
void backTrack(i64 h)
{
  if(h==L){
    check();
   return;}
   
  b[h]=1;
  backTrack(h+1);
  b[h]=3;
  backTrack(h+1);
  b[h]=7;
  backTrack(h+1);
  b[h]=9;
  backTrack(h+1);
}
int main()
{
    sieve();
    for(L=1;L<=3;L++)
     backTrack(0);
      d[0]=2;
      d[o++]=5;
    sort(d,d+o);
    i64 h,l,cnt,i;
    while(scanf("%u",&l)&&l)
    {
     bool flag=0;
     if(l>991){
          printf("0\n");continue;}
     h=pwr(log10(double(l))+1);
     for(i=0;i<o;i++)
      if(d[i]>l&&d[i]<h){
       printf("%u\n",d[i]);flag=1;break;}
      if(!flag)
      printf("0\n");
    }
    return 0;
}
