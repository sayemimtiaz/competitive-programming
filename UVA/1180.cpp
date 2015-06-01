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

//bool prime[131099];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

/*void sieve(int N)
{
     int i,j,prev,dv;
     int M=sqrt(N);
     	for(i=4;i<=N;i+=2)
     	 prime[i]=1;
	for(i=3;i<=N;i+=2)
	{
		if(!prime[i])
		{
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
	}
}*/
int main()
{
   // sieve(131099);
    int n,a,i;
    while(~scanf("%d",&n))
    {
      for(i=0;i<n-1;i++)
      {
       scanf("%d%*c",&a);
      if(a)
         printf("Yes\n");
        else
         printf("No\n");
      }
       scanf("%d",&a);
      if(a==2||a==3||a==5||a==7||a==13||a==17)
         printf("Yes\n");
        else
         printf("No\n");
    }
    return 0;
}
