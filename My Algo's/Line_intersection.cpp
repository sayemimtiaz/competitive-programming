#include<stdio.h>
#include<math.h>
#define MIN(a,b) (a>b)?b:a
#define MAX(a,b) (a>b)?a:b
double p_x[5],p_y[5];
double direction(long i,long j,long k)
{
   return (p_x[k]-p_x[i])*(p_y[j]-p_y[i])-(p_x[j]-p_x[i])*(p_y[k]-p_y[i]);
}
bool on_segment(long i,long j,long k)
{
     if(MIN(p_x[j],p_x[k])<=p_x[i]&&MIN(p_y[j],p_y[k])<=p_y[i])
      if(MAX(p_x[j],p_x[k])>=p_x[i]&&MAX(p_y[j],p_y[k])>=p_y[i])
       return true;
      return false;
}
bool segment_intersect()
{
     double d1,d2,d3,d4;
     d1=direction(3,4,1);
     d2=direction(3,4,2);
     d3=direction(1,2,3);
     d4=direction(1,2,4);
     if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
      return true;
     if(d1==0&&on_segment(3,4,1))
      return true;
     if(d2==0&&on_segment(3,4,2))
      return true;
     if(d3==0&&on_segment(1,2,3))
      return true;
     if(d4==0&&on_segment(1,2,4))
      return true;
}
int main()
{
    long kase;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%lf %lf %lf %lf",&p_x[1],&p_y[1],&p_x[2],&p_y[2]);
       scanf("%lf %lf %lf %lf",&p_x[3],&p_y[3],&p_x[4],&p_y[4]);
       if(segment_intersect())
        printf("Yes,Lines intersect\n");
       else
       printf("NO,Lines don't intersect\n");
    }
    return 0;
}
