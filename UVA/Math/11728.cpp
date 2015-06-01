#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int m[1200];
int SOD(int n)
{
    int i,sum,lim;
    sum=1;
    lim=sqrt(n);
    for(i=2;i<=lim;i++)
      if(n%i==0)
      {
       sum+=i;
       if((n/i)!=i)
       sum+=(n/i);
      }
    sum+=n;
    return sum;
}
void precal()
{
  int d;
  m[1]=1;
  for(int i=2;i<1000;i++)
  {
    d=SOD(i);
    if(d<=1000)
    m[d]=i;
   }
}
int main()
{
    int n,kas=1;
    precal();
    while(scanf("%d",&n)&&n)
    {
      printf("Case %d: %d\n",kas++,(m[n]==0)?-1:m[n]);
    }
    return 0;
}
