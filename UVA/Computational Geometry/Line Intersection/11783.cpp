#include<cstdio>
#include<cmath>
using namespace std;
#define dle double
struct Line
{
double x[2],y[2];
}L[1020];

inline dle MAX(dle a,dle b)
{
  return (a>b)?a:b;
}
inline dle MIN(dle a,dle b)
{
  return (a>b)?b:a;
}
bool ReportLine(Line l1,Line l2)
{
    double A1,A2,B1,B2,C1,C2,Det;
    B1=l1.x[1]-l1.x[0];
    A1=l1.y[0]-l1.y[1];
    C1=A1*l1.x[0]+B1*l1.y[0];
    B2=l2.x[1]-l2.x[0];
    A2=l2.y[0]-l2.y[1];
    C2=A2*l2.x[0]+B2*l2.y[0];
    Det=(A1*B2)-(A2*B1);
    if(Det==0)
    return false;
    double x = ((B2*C1) - (B1*C2))/Det;
    double y = ((A1*C2) - (A2*C1))/Det;
    if(x>=MIN(l1.x[1],l1.x[0])&&x<=MAX(l1.x[1],l1.x[0])&&y>=MIN(l1.y[1],l1.y[0])&&y<=MAX(l1.y[1],l1.y[0]))
     if(x>=MIN(l2.x[1],l2.x[0])&&x<=MAX(l2.x[1],l2.x[0])&&y>=MIN(l2.y[1],l2.y[0])&&y<=MAX(l2.y[1],l2.y[0]))
      return true;
     return false;
} 
int main()
{
    int i,n,cnt,j;
    bool found;
    while(scanf("%d",&n)&&n)
    {
      cnt=0;
      bool mark[1020]={0};
      for(j=0;j<n;j++)
        for(i=0;i<2;i++)
          scanf("%lf %lf",&L[j].x[i],&L[j].y[i]);
      for(i=0;i<n;i++){
       found=0;
       for(j=i+1;j<n;j++)
           if(ReportLine(L[i],L[j]))
            found=1,cnt++,mark[j]=1;
       if(!mark[i]&&!found)
        cnt+=2;
       }
       printf("%d\n",cnt);
    
    }
    return 0;
}
