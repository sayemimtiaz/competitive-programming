#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXPOINT 10000
struct PP
{
  long x,y;     
}P[MAXPOINT];
PP S[MAXPOINT];
long f_x,f_y;
double epsilon;
int ccw(long x1, long y1, long x2, long y2, long x3, long y3)
{
double area;
area = (x1*y2 - x1*y3 + x2*y3 - x2*y1 + x3*y1 - x3*y2)/(double)2.0; 
return area>epsilon;
}
int lower_left(const void *a,const void *b)
{
PP *i = (PP*)a;
PP *j = (PP*)b;
if(i->y != j->y)
return (i->y-j->y);
return (i->x - j->x);
}
int cmp(const void *a,const void *b)
{
PP *i = (PP*)a;
PP *j = (PP*)b;
if(ccw(f_x,f_y,i->x,i->y,j->x,j->y))
 return -1;
else
 return 1;
}
int main()
{
    long n,i,Top;
    epsilon=pow(10,-9);
    while(~scanf("%ld",&n))
    {
      for(i=0;i<n;i++)
       scanf("%ld %ld",&P[i].x,&P[i].y);
      qsort(&P[0],n,sizeof(PP),lower_left);
      f_x=P[0].x;f_y=P[0].y;
      qsort(&P[1],n-1,sizeof(PP),cmp);
      S[0]=P[0];
      S[1]=P[1];
      S[2]=P[2];
      Top=3;
      for(i=3;i<n;i++)
      {
        while(!ccw(S[Top-2].x,S[Top-2].y,S[Top-1].x,S[Top-1].y,P[i].x,P[i].y))
         Top--;
        S[Top++]=P[i];
      }
      printf("Points of Convex Hull Are:\n");
      for(i=0;i<Top;i++)
       printf("%ld %ld\n",S[i].x,S[i].y);
    }
    return 0;
}
