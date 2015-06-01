#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct SS
{
       long x,y;
}S[5];
double epsilon;
long B1,B2,B3,B4,D1,D2,f_x,f_y;
int lower_left(const void *a, const void *b)
{
SS *i = (SS*)a;
SS *j = (SS*)b;
if(i->y != j->y)
return (i->y-j->y);
return (i->x - j->x);
}
int ccw(double x1, double y1, double x2, double y2, double x3, double y3)
{
double area;
area = (x1*y2 - x1*y3 + x2*y3 - x2*y1 + x3*y1 - x3*y2)/(double)2.0; 
return area>epsilon;
}
int smaller_angle(const void *a, const void *b)
{
SS *i = (SS*)a;
SS *j = (SS*)b;
if(ccw(f_x,f_y,i->x,i->y,j->x,j->y))
return -1;
else return 1;
}

bool isninty()
{
     if((B1+B2)==D2&&(B1+B4)==D1&&(B2+B3)==D1&&(B4+B3)==D2)
      return true;
     return false;
}
bool isparralel()
{
   long cross,T1,T2,T3,T4;
   T1 = S[0].x-S[1].x;
   T2 = S[0].y-S[1].y;
   T3 = S[3].x-S[2].x;
   T4 = S[3].y-S[2].y;
   cross = (T1 * T4) - (T2 * T3);
   if(!cross)
    return true;
   T1 = S[3].x-S[0].x;
   T2 = S[3].y-S[0].y;
   T3 = S[1].x-S[2].x;
   T4 = S[1].y-S[2].y;
   cross = (T1 * T4) - (T2 * T3);
   if(!cross)
    return true;
 return false;
}
int main()
{
    long temp,i,kase,kas=1;
    scanf("%ld",&kase);
    epsilon=pow(10,-9);
    while(kase--)
    {
      for(i=0;i<4;i++)
       scanf("%ld %ld",&S[i].x,&S[i].y);
      qsort(S,4,sizeof(SS),lower_left); // find out the first point
      f_x = S[0].x; f_y = S[0].y;
      qsort(&S[1],3,sizeof(SS),smaller_angle);
      B1=(S[0].x-S[1].x)*(S[0].x-S[1].x)+(S[0].y-S[1].y)*(S[0].y-S[1].y);
      B2=(S[1].x-S[2].x)*(S[1].x-S[2].x)+(S[1].y-S[2].y)*(S[1].y-S[2].y);
      B3=(S[2].x-S[3].x)*(S[2].x-S[3].x)+(S[2].y-S[3].y)*(S[2].y-S[3].y);
      B4=(S[3].x-S[0].x)*(S[3].x-S[0].x)+(S[3].y-S[0].y)*(S[3].y-S[0].y);
      D1=((S[1].x-S[3].x)*(S[1].x-S[3].x)+(S[1].y-S[3].y)*(S[1].y-S[3].y));
      D2=((S[2].x-S[0].x)*(S[2].x-S[0].x)+(S[2].y-S[0].y)*(S[2].y-S[0].y));
      printf("Case %ld: ",kas++);
      if(B1==B2&&B2==B3&&B3==B4)
      {
         if(isninty())
          printf("Square");
         else
          printf("Rhombus");
      }
      else if(B1==B3&&B2==B4)
      {
         if(isninty())
          printf("Rectangle");
         else
          printf("Parallelogram");
      }
      else if(isparralel())
       printf("Trapezium");
      else
       printf("Ordinary Quadrilateral");
      printf("\n");
    }
    return 0;
}
