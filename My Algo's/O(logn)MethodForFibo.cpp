#include<stdio.h>
#include<math.h>
void powr(long F[2][2],int n);
void multiply(long F[2][2],long M[2][2]);
long  fibo(int n)
{
     long F[2][2]={1,1,1,0};
     if(n==0)
      return 1;
     powr(F,n-1);
     return F[0][0];
}
void  powr(long F[2][2],int n)
{
      if(n<=1)
       return;
      long M[2][2]={1,1,1,0};
      powr(F,n/2);
      multiply(F,F);
      if(n%2)
       multiply(F,M);
}
void multiply(long F[2][2], long M[2][2])
{
  long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long  z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
     printf("%ld\n",fibo(n));
    return 0;
}
