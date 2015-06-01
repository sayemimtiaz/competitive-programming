#include<stdio.h>
#include<string.h>
bool flag1[100009],flag2[100009];
int main()
{
    int A,B,cnt1,cnt2,n;
    while(scanf("%d %d",&A,&B)&&(A||B))
    {
       cnt2=0;
       while(A--)
       {
         scanf("%d",&n);
         if(flag1[n])
          continue;
         flag1[n]=1;
         cnt2++;
       }
       cnt1=0;
       while(B--)
       {
         scanf("%d",&n);
         if(flag1[n])
         {
           cnt2--;
           flag1[n]=0;
           flag2[n]=1;
           continue;
         }
         if(flag2[n])
         continue;
         flag2[n]=1;
         cnt1++;
       }
       printf("%d\n",(cnt1>cnt2)?cnt2:cnt1);
       memset(flag1,0,sizeof(flag1));
       memset(flag2,0,sizeof(flag2));
    }
    return 0;
}
