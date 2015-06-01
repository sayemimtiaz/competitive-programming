#include<stdio.h>
#include<math.h>

int main()
{
    int kase,i,k,p,q,l,j,z;
    long long sum,a[200],r;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&p,&q);
      if(p==0)
      {printf("0\n");continue;}
      z=p/2;if(p%2)z++;
      if(p%2==0||z>q)
      a[0]=1,i=1,p--;
      else
      {
       i=0;
      a[i++]=1,p--;
      if(p)
      a[i++]=1,p--;
      }
      while(p)
      {
        if(q)
        a[i++]=0,q--;
        if(p)
        a[i++]=1,p--;
        if(p)
        a[i++]=1,p--;
      }
      for(sum=0,k=0,j=i-1;k<i;k++,j--)
      {
       if(a[k])
       {
        r=1;
        for(l=1;l<=j;l++)
         r*=2;
         sum+=r;
       }
      }
      printf("%lld\n",sum);
    }
    return 0;
}
