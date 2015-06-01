#include<stdio.h>
#include<math.h>
int main()
{
    double n;
    long p;
    while(scanf("%lf",&n)==1)
    {
      p=log(n)/log(2);
      printf("%ld\n",p+1);
    }
    return 0;
}
