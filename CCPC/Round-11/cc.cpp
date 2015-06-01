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

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
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
int a[100],c;

void sieve()
{
     bool prime[305]={0};
     int i,j;
     	a[0]=2;c=1;
	for(i=3;i<=85;i+=2)
	{
		if(!prime[i])
		{         
            a[c++]=i;
            if(i<=9)
			for(j=i*i;j<=85;j+=2*i)
				prime[j]=1;
		}
	}
	
}
int main()
{
    int i,j,n,r,nn,d,o,l[3005],kk;
    sieve();
    while(~scanf("%d %d",&n,&r))
    {
         int F[3005]={0};
         for(i=n-r;i>1;i--)
         {nn=i;
         for(j=0;a[j]<nn&&j<c;)
         {
             if(nn%a[j]==0)
             {
               F[a[j]]--;
               nn/=a[j];
             }
             else
              j++;
             }
             F[nn]--;
           }
      
       for(i=r+1;i<=n;i++)
        {
           nn=i;
           for(j=0;a[j]<nn&&j<c;)
           {
                                
             if(nn%a[j]==0)
             {
               F[a[j]]++;
               nn/=a[j];
             }
             else
              j++;
             }
             F[nn]++;
           }
           
           printf("%dC%d = ",n,r);
          bool flag=0;
          
           for(i=2;i<=3000;i++)
            for(j=1;j<=F[i];j++)
            {
                 if(flag)
                                 printf(" * ");
                                 flag=1;
                        printf("%d",i);
            }
            printf("\n");
    }
    return 0;
}
