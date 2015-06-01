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
#define i64 unsigned long long
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
i64 flag[800],a[10000],c;
bool mark[1000009];
void sieve()
{
  i64 mx=46341;
  i64 lmt=216;
  i64 i,j,k;
  c=0;
  for(i=3;i<=mx;i+=2)
   if(!chkC(flag,i))
   {
     a[++c]=i;
     if(i<=lmt)
      for(j=i*i,k=i<<1;j<=mx;j+=k)
       setC(flag,j);
   }
}
int main()
{
    sieve();
    i64 L,U,sa,sb,la,lb,min,max,i,val,j,k,aa,lmt,Ol;
    while(~scanf("%llu %llu",&L,&U))
    {
      lmt=sqrt(U);
      if(L==1)
       L=2;
      for(i=1;a[i]<=lmt&&i<=c;i++){
       val=L/a[i];
       if(val%2==0)
        val++;
       if(val==1)
        val=3;
       for(j=a[i]*val,k=a[i]<<1;j<=U;j+=k)
      //  if(j-L>=0&&j-L<1000009)
         mark[j-L]=1;
       }
       Ol=L;
       aa=0;
       if(L<=2)
        aa=2;
       if(L%2==0)
        L++;
       for(i=L;!aa&&i<=U;i+=2)
        if(!mark[i-Ol]){
         aa=i;i+=2;break;}
         min=INT_MX;
         max=0;
        for(;i<=U;i+=2)
        if(!mark[i-Ol]){
         if(i-aa<min)
          min=i-aa,sa=aa,sb=i;
           if(i-aa>max)
          max=i-aa,la=aa,lb=i;
          aa=i;
          //printf("%u\n",i);
          }
         if(max==0)
          printf("There are no adjacent primes.\n");
         else
          printf("%llu,%llu are closest, %llu,%llu are most distant.\n",sa,sb,la,lb);
         mems(mark);
    }
    return 0;
}
