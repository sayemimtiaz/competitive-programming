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
bool vis[20];
int save,n,k,b[20];
char a[20][20];



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

void redo()
{
  char c[20],m1[20],m2[20];
  int aa,bb,i,j;
  c[k]='\0';
  for(i=0;i<n;i++)
  {
    for(j=0;j<k;j++)
      c[j]=a[i][b[j]];
    if(!i)
     strcpy(m1,c),strcpy(m2,c);
    else if(strcmp(c,m1)>0)
     strcpy(m1,c);
    else if(strcmp(c,m2)<0)
     strcpy(m2,c);
   }
   sscanf(m1,"%d",&aa);
   sscanf(m2,"%d",&bb);
   aa=aa-bb;
      // printf("%d\n",aa);
   if(save>aa)
    save=aa;
}

void check(int h)
{
  if(h==k)
  {
    redo();
   return;
   }
  for(int i=0;i<k;i++)
   if(!vis[i])
   {
     vis[i]=1;
     b[h]=i;
     check(h+1);
     vis[i]=0;
   }
}
int main()
{
    int i;
    while(scanf("%d %d",&n,&k)==2)
    {
      for(i=0;i<n;i++)
       scanf("%s",a[i]);
      save=INT_MX;
      check(0);
      printf("%d\n",save);
    }
    return 0;
}
