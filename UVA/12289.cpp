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
    char str[10];
    int kase,t,o,i;
   char S[5][10]={"one","two","three"};
   scanf("%d",&kase);
    while(kase--)
    {
      scanf("%s",str);
      t=o=0;
      for(i=0;str[i]!='\0';i++)
       {if(i==3)
       {
       printf("3\n");
        break;
        }
        if(str[i]==S[0][i])
        o++;
       if(str[i]==S[1][i])
        t++;
       }
       if(str[i]=='\0')
        if(t>o)
         printf("2\n");
        else
         printf("1\n");
    }
    return 0;
}
