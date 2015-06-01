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
#define mems(x) memset(x,0,sizeof(x))

i64 c,a[19000];
bool prime[60000];

void fac(i64 n)
{
     i64 nn=n;
     i64 cnt=0, i,div=1;
     bool flag=0;
     double s,prev,f;
     s=n;
     for(i=0;i<c&&a[i]<=n;)
      {
            if(n%a[i]==0)
            {
               if(!flag)
                 flag=1;
               else if(prev!=a[i]){
                 div*=(cnt+1);
                 s*=(1.0-(1.0/(double)prev));       
                 cnt=0;
                 }   
               prev=a[i];
                n/=a[i];
                cnt++;
            }
            else
              i++;
      }
      if(!flag)
       printf("0\n");
      else{
      if(flag)
      s*=(1.0-(1.0/(double)prev));
      if(n!=1)
       s*=(1.0-(1.0/(double)n));
       if(flag)
       div*=(cnt+1);
      if(n!=1)
       div*=2;
     //  printf("%lld %lf",div,s);
     f=s-floor(s+eps);
     if(f>0.499999)
      f=floor(s+eps)+1;
     else
      f=floor(s+eps);
     nn=nn-(div-2)-f-1;
       printf("%lld\n",nn);
       }
}
void sieve(int N)
{
     i64 i,j;
     i64 M=sqrt(N);
	a[0]=2;c=1;
	for(i=3;i<=N;i+=2)
	{
		if(!prime[i])
		{
            a[c++]=i;
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
	}
}

int main()
{
    i64 n;
    sieve(50350);
    while(scanf("%lld",&n)&&n)
    {
     fac(n);
    }
    return 0;
}
