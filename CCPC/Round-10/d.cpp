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

char str[1000][1000];

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
    int fr[500]={0};
    int max,i,j,k,a,b,n;
    char mc;
    max=-1;
    i=0;
    while(gets(str[i]))
    {
      for(j=0;str[i][j]!='\0';j++)
       if((str[i][j]>='a'&&str[i][j]<='z')||(str[i][j]>='A'&&str[i][j]<='Z')){
        fr[str[i][j]]++;
        if(fr[str[i][j]]>max)
         max= fr[str[i][j]],mc=str[i][j];
        }
        i++;
    }
    mc=tolower(mc);
    n='i'-mc;
    for(j=0;j<i;j++)
    {
       for(k=0;str[j][k]!='\0';k++){
       if(str[j][k]>='A'&&str[j][k]<='Z')
       {
         a=str[j][k]+n;
         if(a<65)
          a='z'-('a'-a-1);
         else if(a>90)
          a='a'+(a-'z'-1);
         printf("%c",a);
         }
         else if(str[j][k]>='a'&&str[j][k]<='z')
       {
         a=str[j][k]+n;
         if(a<97)
          a='Z'-('A'-a-1);
         else if(a>122)
          a='A'+(a-'Z'-1);
         printf("%c",a);
         }
         else
         printf("%c",str[j][k]);
       }
       printf("\n");
    }
   // getchar();
  //  getchar();
    return 0;
}
