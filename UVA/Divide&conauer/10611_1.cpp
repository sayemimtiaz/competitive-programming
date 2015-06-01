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
#define SIZE 50009
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

int a[SIZE],t[SIZE];

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
    int j,n,m,b,e,q,i,el;
    bool found;
    while(~scanf("%d",&j))
	{
		for(i=0;i<j;i++)
			scanf("%d",&t[i]);
		n=0;
		for(i=1;i<j;i++)
		 if(t[i]!=t[i-1])
		  a[n++]=t[i-1];
	   a[n++]=t[i-1];
		scanf("%d",&q);
		while(q--)
        {
          scanf("%d",&el);
          b=0;e=n-1;
          found=0;
          while(b<=e)
          {
            m=(b+e)/2;
            //printf("%d\n",a[m]);
            if(a[m]<el&&(m+1==n||a[m+1]>=el))
            { printf("%d ",a[m]);found=1;break;}
            else if(a[m]<el)
             b=m+1;
            else
             e=m-1;
          }
          if(!found)
          {
           printf("X ");
           if(a[m]>el)
            printf("%d",a[m]);
           else if(m+1==n)
            printf("X");
           else
            printf("%d",a[m+1]);
          }
          else
          {
          if(m+1==n)
            printf("X");
          else if(a[m+1]!=el)
           printf("%d",a[m+1]);
         else if(m+2==n)
            printf("X");
         else
          printf("%d",a[m+2]);
          }
          printf("\n");
        }
    }
    return 0;
}
