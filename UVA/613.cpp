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
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
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
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
}
char temp[20][200];

int check(int j)
{
  int i,k;
  for(k=1,i=j-1;i>=0;i--,k++)
   if(!strcmp(temp[j],temp[i]))
     return k;
  return 0;
}
int main()
{
    int i,j,k;
    while(scanf("%s",temp[0])&&temp[0][0]!='-')
    {
      j=0;
      bool flag=0;
      while(j<15)
      {
        int F[20]={0};
        for(i=0;temp[j][i];i++) F[temp[j][i]-'0']++;
        for(k=i=0;i<10;i++)
         if(F[i]){
           if(F[i]>9)
           temp[j+1][k++]=(F[i]/10)+'0';
           temp[j+1][k++]=(F[i]%10)+'0';
           temp[j+1][k++]=i+'0';
           }
         temp[j+1][k]='\0';
         if(!strcmp(temp[j],temp[j+1])){
          if(j) printf("%s is self-inventorying after %d steps\n",temp[0],j); 
          else printf("%s is self-inventorying\n",temp[0]);
          flag=1;break;}
         else if(k=check(j+1)){
           printf("%s enters an inventory loop of length %d\n",temp[0],k);
           flag=1;break;}
        // printf("%s\n",temp[j+1]);
         j++;
      }
      if(!flag)
       printf("%s can not be classified after 15 iterations\n",temp[0]);
    }
    return 0;
}
