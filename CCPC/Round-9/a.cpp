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

int main()
{
    char str[1000],st[1000];
    int len,r,i,j;
    bool flag,yes;
    while(~scanf("%s %d",str,&r))
    {
       for(i=0;str[i]=='0';i++);
       strcpy(str,&str[i]);
       if(str[0]=='\0')
        str[0]='0',str[1]='\0';
        len=strlen(str);
        if(strcmp(str,"0")==0||r==0){
         printf("%s\n",str);
         continue;}
        
      yes=0;
     
         flag=0;
       for(j=0;j<len;j++)
         if(str[j]=='0')
          {flag=1;break;}
          
       for(i=1;flag;i++)
      {
        for(j=1;j<len;j++)
         st[j]=str[j-1];
         
        st[0]=str[len-1];
        st[len]='\0';
        strcpy(str,st);
      for(j=0;str[j]=='0';j++);
      strcpy(str,&str[j]);
      len=strlen(str);
      flag=0;
       for(j=0;j<len;j++)
         if(str[j]=='0')
          {flag=1;break;}
       if(i==r){yes=1;
         printf("%s\n",str);}
      }
      if(yes)
       continue;
      r-=(i-1);
    len=strlen(str);
      r=r%len;
      for(i=1;i<=r;i++)
      {
        for(j=1;j<len;j++)
         st[j]=str[j-1];
        st[0]=str[len-1];
        st[len]='\0';
        strcpy(str,st);
      }
      printf("%s\n",str);
    }
    return 0;
}
