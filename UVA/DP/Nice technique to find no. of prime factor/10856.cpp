#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
#define SIZE 5000
bool prime[SIZE];
long a[SIZE],c;
long ff[10000009];
long mm[10000009];
long fac(long n)
{
     long i;
      for(i=0;i<c&&a[i]<=n;i++)
            if(n%a[i]==0)
               return a[i];
        return n;

}
void sieve(long N)
{
     long i,j,pp,cur,prev;
     long M=sqrt(N);
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
	ff[1]=0;ff[2]=1;mm[0]=0;mm[1]=2;pp=1;
	for(i=3;i<=2703663;i++)
	{
      prev=fac(i);
      ff[i]=ff[i/prev]+1;
      cur=pp+ff[i];
      mm[cur]=i;
      pp=cur;
    }
}
int main()
{
    long n,kas=1;
    sieve(3164);
    while(scanf("%ld",&n)&&n>=0)
    {
      printf("Case %ld: ",kas++);
      if(n==0)
       printf("0!\n");
      else if(!mm[n])
       printf("Not possible.\n");
      else
       printf("%ld!\n",mm[n]);
    }
    return 0; 
}
