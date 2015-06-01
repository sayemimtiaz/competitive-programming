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
int main()
{
    char s1[1000],str[1000];
    int i,j;
    while(scanf("%s",str)==1)
    {
      bool f[500]={0};
      f['I']=1;
       f['A']=1; f['O']=1; f['Y']=1;
       f['E']=1;f['U']=1;
        f['i']=1;
       f['a']=1; f['o']=1; f['y']=1;
       f['e']=1;f['u']=1;
       j=0;
       for(i=0;str[i]!='\0';i++)
        if(!f[str[i]])
         s1[j++]='.',s1[j++]=tolower(str[i]);
        s1[j]='\0';
      printf("%s\n",s1);
      
    }
    return 0;
}
