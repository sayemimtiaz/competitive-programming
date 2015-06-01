#include<stdio.h>
#include<math.h>
#define MAX 100009
 long D[MAX];
 double S[MAX];
int main()
{
    long kase,d,i,j,how,a,b,k,lim;
    double sum;
    for(i=1;i<=MAX;i++)
    {
       lim=sqrt(i);
       how=0;
       sum=0;
       for(j=1;j<=lim;j++)
       {
         if(i%j==0)
         {
           how++;sum+=j;
           a=i/j;
           if(a!=j)
           {how++;sum+=a;}
         }
       }
       D[i]=how;S[i]=sum;
    }
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld %ld %ld",&a,&b,&k);
      d=0;
      sum=0;
      for(j=1,i=k;i<=b;j++,i=k*j)
      if(i>=a)
      {d+=D[i];sum+=S[i];}
      printf("%ld %0.lf\n",d,sum);
    }
    return 0;
}
