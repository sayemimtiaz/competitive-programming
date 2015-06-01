#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define SIZE 2000109
using namespace std;

struct SS
{
  int A;
  int F;
}S[SIZE];

int c,a[SIZE];
bool prime[SIZE];

bool cmp(SS x,SS y)
{
  if(x.F!=y.F)
   return (x.F<y.F);
  return (x.A<y.A);
}

int fac(int n)
{
     int i;
      for(i=0;i<c&&a[i]<n;i++)
            if(n%a[i]==0)
               return a[i];

}

void sieve(int N)
{
     int i,j;
     int M=sqrt(N);
	for(i=4;i<=N;i+=2)
		prime[i]=1;
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
	S[0].F=0;S[0].A=0;
	S[1].F=S[2].F=S[3].F=1;
	S[1].A=1;S[2].A=2;S[3].A=3;
	for(i=4;i<=2000000;i++)
	{
       S[i].A=i;
       if(!prime[i]){
        S[i].F=1;continue;}
       S[i].F=1+S[i/fac(i)].F;
    }
    sort(S,S+2000001,cmp);
 }
int main()
{
    int i,n,kas=1;
    sieve(2000014);
    while(scanf("%d",&n)&&n)
    {
        printf("Case %d: %d\n",kas++,S[n].A);
    }
    return 0;
}
