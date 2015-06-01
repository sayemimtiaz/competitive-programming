#include<stdio.h>
#include<math.h>
double x[10],y[10];
void ReportLine()
{
    double A1,A2,B1,B2,C1,C2,Det;
    B1=x[1]-x[0];
    A1=y[0]-y[1];
    C1=A1*x[0]+B1*y[0];
    B2=x[3]-x[2];
    A2=y[2]-y[3];
    C2=A2*x[2]+B2*y[2];
    Det=(A1*B2)-(A2*B1);
    if(Det==0)
    {printf("Lines are parallel\n");return;}
    double x = ((B2*C1) - (B1*C2))/Det;
    double y = ((A1*C2) - (A2*C1))/Det;
    printf("Intersection Points are:\nX=%lf\nY=%lf\n",x,y);

} 
int main()
{
    int i,kase;
    scanf("%d",&kase);
    while(kase--)
    {
    for(i=0;i<4;i++)
    scanf("%lf %lf",&x[i],&y[i]);
    ReportLine();
    }
    return 0;
}
