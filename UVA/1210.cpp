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

bool prime[10002];
int a[1300],c;

void sieve(int n)
{
     int i,j;
     int M=sqrt(n);
	a[0]=2;c=1;
	for(i=3;i<=n;i+=2)
	{
		if(!prime[i])
		{
           // if(c<168)         
            a[c++]=i;
            if(i<=M)
			for(j=i*i;j<=n;j+=2*i)
				prime[j]=1;
		}
	}
}
int main()
{
    int r,n,i,j,s;
    sieve(10001);
    printf("%d\n",c);
    
    while(scanf("%d",&n)&&n)
    {
    
       r=0;
       for(i=0;i<c&&a[i]<=n;i++)
       {
                                s=0;
         //s=a[i];
         //if(s==n)
         //{r++;break;}
        for(j=i;j<c;j++)
        {
            s+=a[j];
          if(s==n)
           {r++;break;}
          if(s>n)
           break;
        }
       }
       printf("%d\n",r);
    }
    return 0;
}
