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
int main()
{
    long kase,iso,ns,i,j;
    bool vis[120],found=0;
    double xs[120],ys[120],xe[120],ye[120];
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld",&ns);
       for(i=1;i<=ns;i++)
       {vis[i]=0;scanf("%lf %lf %lf %lf",&xs[i],&ys[i],&xe[i],&ye[i]);}
       iso=0;
       for(i=1;i<=ns;i++)
        if(!vis[i])
        {
         found=0;vis[i]=1;
         p_x[1]=xs[i];p_y[1]=ys[i];
         p_x[2]=xe[i];p_y[2]=ye[i];
        for(j=1;j<=ns;j++)
        {
         if(i!=j)
         {
         p_x[3]=xs[j];p_y[3]=ys[j];
         p_x[4]=xe[j];p_y[4]=ye[j];
         if(segment_intersect(1,2,3,4))
          {vis[j]=1;found=1;}
         }
         }
         if(!found)
          iso++;
         }
        printf("%ld\n",iso);
    }
    return 0;
}
