#include<stdio.h>
#include<math.h>
int main()
{
    int kase;
    double a,g,l,i;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%lf %lf",&g,&l);
      if(fmod(l,g))
      {printf("-1\n");continue;}
      a=g*l;
      bool flag=0;
      for(i=g;i<=l;i+=g)
      {
        if(fmod(a,i)==0)
        {flag=1;printf("%0.lf %0.lf\n",i,(a/i));break;}
      }
      if(!flag)
       printf("-1\n");
    }
    return 0;
}
