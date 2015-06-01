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
    char str[1000],*pch;
    int i,j,n;
    bool got;
    i64 c,C,a,b,w[1000];
    while(gets(str))
    {
       printf("%s\n",str);
       pch=strtok(str," ");
       n=0;C=1;
       while(pch!=NULL)
       {
         w[n]=0;
         for(i=0;pch[i]!='\0';i++)
          w[n]=w[n]*32+(pch[i]-'a'+1);
         pch=strtok(NULL," ");
         C=MIN(C,w[n]);
         n++;
       }
       while(1)
       {
        c=1;got=0;
       for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
          a=C/w[i];b=C/w[j];
          if(i!=j&&(a%n)==(b%n))
          got=1,c=MAX(c,MIN((a+1)*w[i],(b+1)*w[j]));
        }
        if(!got){
         printf("%lld\n",C);break;}
         C=c;
       }
       printf("\n");
          
    }
    return 0;
}
