#include<stdio.h>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a>b)?b:a
int main()
{
    int kase,xll1,xll2,xur1,xur2,yur1,yur2,yll1,yll2;
    bool flag=0;
    scanf("%d",&kase);
    while(kase--)
    {
       scanf("%d %d %d %d",&xll1,&yll1,&xur1,&yur1);
       scanf("%d %d %d %d",&xll2,&yll2,&xur2,&yur2);
       if(flag)
        printf("\n");
       flag=1;
       if(xll2>=xur1||xur2<=xll1||yll2>=yur1||yur2<=yll1)
        printf("No Overlap\n");
       else
        printf("%d %d %d %d\n",MAX(xll1,xll2),MAX(yll1,yll2),MIN(xur1,xur2),MIN(yur1,yur2));
    }
    return 0;
}
