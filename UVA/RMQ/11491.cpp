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

int a[SIZE],s[SIZE],m[SIZE],pp[SIZE];
char num[SIZE];

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
    int n,i,j,b,max,q,c,g,x,y,mm,index;
    while(scanf("%d %d",&n,&mm)&&(n||mm))
    {
     scanf("%s",&num);
    for(i=1;i<=n;i++)
     a[i]=num[i-1]-'0';
    b=sqrt(n);g=b;
    if(b*b!=n)g++;j=1;
    for(i=1;i<=g;i++)
    {
       for(pp[i]=j,s[j]=i,c=j,max=a[j++];j<(c+b)&&j<=n;j++){
         if(max<a[j])
         {                                           
        max=MAX(max,a[j]);
        pp[i]=j;
        }
        s[j]=i;
        }
      m[i]=max;
    }
    x=1;mm=n-mm;
    for(j=mm-1;j>=0;j--)
    {
      y=n-j;
      max=INT_MN;
      for(i=x;i<=y;)
      {
        if(((i+b-1)<=y&&s[i+b-1]==s[i])||((i+b-1)==n+b))
        {
           if(max<m[s[i]]){
           max=m[s[i]];
           index=pp[s[i]]+1;
           }
           i+=b;
           }
        else
        {
          if(max<a[i]){
           max=a[i];
           index=i+1;
           }
           i++;
        }
      }
      printf("%d",max);
      x=index;
    }
    printf("\n");
    }
    return 0;
}
