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

int main()
{
    int kas=1;
    string str;
    map<string,string>m;
    m["HELLO"]="ENGLISH";
    m["HOLA"]="SPANISH";
    m["HALLO"]="GERMAN";
    m["BONJOUR"]="FRENCH";
    m["CIAO"]="ITALIAN";
    m["ZDRAVSTVUJTE"]="RUSSIAN";
    while(cin>>str&&str[0]!='#')
    {
       cout<<"Case "<<kas++<<": ";
       if(m.find(str)!=m.end())
        cout<<m[str]<<endl;
       else
        cout<<"UNKNOWN"<<endl;
    }
    return 0;
}
