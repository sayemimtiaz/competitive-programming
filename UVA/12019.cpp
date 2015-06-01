#include<stdio.h>
int main()
{
    int w,dd[13][40],kase,i,j,M,D;
    int MM[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int MMD[12]={5,1,1,4,6,2,4,0,3,5,1,3};
    char day[7][20]={"Monday","Tuesday","Wednesday",
                     "Thursday","Friday","Saturday","Sunday"};
    for(i=0;i<12;i++)
    {
      w=MMD[i]-1;
     for(j=1;j<=MM[i];j++)
         dd[i][j]=w=(w+1)%7;
     }
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&M,&D);
      printf("%s\n",day[dd[M-1][D]]);
    }
    return 0;
}
