#include<stdio.h>
#include<math.h>
 unsigned long long m;
void powr( unsigned long long F[2][2],long n);
void multiply( unsigned long long F[2][2], unsigned long long M[2][2]);
void  fibo(long n)
{
     unsigned long long F[2][2]={1,1,1,0};
     if(n==0)
      printf("0\n");
     else
     {
     powr(F,n-1);
     printf("%llu\n",F[0][0]%m);
     }
}
void  powr(unsigned long long F[2][2],long n)
{
      if(n<=1)
       return;
      unsigned long long M[2][2]={1,1,1,0};
      powr(F,n/2);
      multiply(F,F);
      if(n%2)
       multiply(F,M);
}
void multiply(unsigned long long F[2][2], unsigned long long M[2][2])
{
  unsigned long long x,y,z,w;
   x =  (((F[0][0]%m)*(M[0][0]%m))%m + ((F[0][1]%m)*(M[1][0]%m))%m)%m;
   y =  (((F[0][0]%m)*(M[0][1]%m))%m + ((F[0][1]%m)*(M[1][1]%m))%m)%m;
   z =  (((F[1][0]%m)*(M[0][0]%m))%m + ((F[1][1]%m)*(M[1][0]%m))%m)%m;
   w =  (((F[1][0]%m)*(M[0][1]%m))%m + ((F[1][1]%m)*(M[1][1]%m))%m)%m;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
int main()
{
    long n;
    while(~scanf("%ld %llu",&n,&m))
    {
     m=pow(2,m);
     fibo(n);
    }
    return 0;
}
