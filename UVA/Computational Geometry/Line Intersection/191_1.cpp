#include<stdio.h>
#include<math.h>
#define MIN(a,b) (a>b)?b:a
#define MAX(a,b) (a>b)?a:b
double p_x[5],p_y[5];
double tlx,tly,brx,bry;
double direction(long i,long j,long k)
{
   return (p_x[k]-p_x[i])*(p_y[j]-p_y[i])-(p_x[j]-p_x[i])*(p_y[k]-p_y[i]);
}
bool on_segment(long i,long j,long k)
{
     double a=MIN(p_x[j],p_x[i]);
     double b=MIN(p_y[j],p_y[i]);
     double c=MAX(p_x[j],p_x[i]);
     double d=MAX(p_y[j],p_y[i]);
     if(p_x[k]>=a&&p_y[k]>=b&&p_x[k]<=c&&p_y[k]<=d)
       return true;
      return false;
}
bool segment_intersect(long i,long j,long k,long l)
{
     double d1,d2,d3,d4;
     d1=direction(k,l,i);
     d2=direction(k,l,j);
     d3=direction(i,j,k);
     d4=direction(i,j,l);
     if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
      return true;
     if(d1==0&&on_segment(k,l,i))
      return true;
     if(d2==0&&on_segment(k,l,j))
      return true;
     if(d3==0&&on_segment(i,j,k))
      return true;
     if(d4==0&&on_segment(i,j,l))
      return true;
     return false;
}
bool in_rec()
{
     if(p_x[1]>=tlx&&p_x[1]<=brx&&p_y[1]<=tly&&p_y[1]>=bry)
      return true;
      if(p_x[2]>=tlx&&p_x[2]<=brx&&p_y[2]<=tly&&p_y[2]>=bry)
      return true;
      return false;
}
int main()
{
    long kase;
    double temp;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%lf %lf %lf %lf",&p_x[1],&p_y[1],&p_x[2],&p_y[2]);
       scanf("%lf %lf %lf %lf",&tlx,&tly,&brx,&bry);
       if( tlx>brx)
       {temp =brx;brx=tlx;tlx=temp;
        temp =bry;bry=tly;tly=temp;
       } 
       if(tly<bry)
       {
          temp=tly;tly=bry;bry=temp;
       }
       p_x[3]=tlx;p_y[3]=tly;p_x[4]=brx;p_y[4]=bry;
       if(tlx==brx||tly==bry)
       {
        if(segment_intersect(1,2,3,4))
         { printf("T\n");continue;}
         printf("F\n");
         continue;
        }
       if(in_rec())
       {printf("T\n");continue;}
       p_x[3]=tlx;p_y[3]=tly;p_x[4]=tlx;p_y[4]=bry;
       if(segment_intersect(1,2,3,4))
       { printf("T\n");continue;}
       p_x[4]=brx;p_y[4]=tly;
       if(segment_intersect(1,2,3,4))
       { printf("T\n");continue;}
       p_x[3]=brx;p_y[3]=bry;
       if(segment_intersect(1,2,3,4))
       { printf("T\n");continue;}
        p_x[3]=tlx;p_y[3]=bry;p_x[4]=brx;p_y[4]=bry;
       if(segment_intersect(1,2,3,4))
       { printf("T\n");continue;}
       printf("F\n");
    }
    return 0;
}
