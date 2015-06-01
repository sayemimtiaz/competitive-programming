#include<stdio.h>
#include<math.h>
double x[10],y[10];
bool IsSameLine()
{
     return ((x[0]*(y[1]-y[2])+x[1]*(y[2]-y[0])+x[2]*(y[0]-y[1]))==0);
}
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
    {
    if(IsSameLine())
    printf("LINE\n");
    else
    printf("NONE\n");
    return;
    }
    double x = ((B2*C1) - (B1*C2))/Det;
    double y = ((A1*C2) - (A2*C1))/Det;
    printf("POINT %0.2lf %0.2lf\n",x,y);

} 
int main()
{
    int i,n;
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--)
    {
    for(i=0;i<4;i++)
    scanf("%lf %lf",&x[i],&y[i]);
    ReportLine();
    }
    printf("END OF OUTPUT\n");
    return 0;
}
