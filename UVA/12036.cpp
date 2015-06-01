#include<stdio.h>
#include<string.h>
int fr[500];
int main()
{
    int kase,kas=1,i,j,a,n;
    bool flag;
    scanf("%d",&kase);
    while(kase--)
    {
       flag=1;
       scanf("%d",&n);
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
          scanf("%d",&a);
          fr[a]++;
          if(fr[a]>n)
           flag=0;
        }
        printf("Case %d: ",kas++);
        if(flag)
         printf("yes\n");
        else
         printf("no\n");
        memset(fr,0,sizeof(fr));
    }
    return 0;
}
