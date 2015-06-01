#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
int main()
{
    double l,w,h,q,a,r;
    while(~scanf("%lf %lf %lf %lf",&l,&w,&h,&q))
    {
      a=(q*PI)/180;
      a=l*tan(a);
      if((h-a)>1e-9)
       r=(w*h*l)-((a*l*w)/(double)2);
      else
      {
        a=((90-q)*PI)/180;
       a=h*tan(a);
       r=((a*h*w)/(double)2);
       }
       printf("%0.3lf mL\n",r);
    }
    return 0;
}
