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

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

void div(char *s,int num)
{
	int i,hold;
	for(i=0,hold=0;s[i]!='\0';i++)
	{
		hold=hold*10+(s[i]-'0');
		hold%=num;
	}
	printf("%d\n",hold);
}
int main()
{
    int kase,n;
    char p[12000];
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      scanf("%s",p);
      div(p,n);
    }
    return 0;
}
