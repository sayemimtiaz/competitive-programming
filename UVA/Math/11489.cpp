#include<stdio.h>
int main()
{
    int kas=1,kase,i,cnt,a,b,sum;
    bool flag;
    char num[10000];
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%s",num);
      sum=0;
      for(i=0;num[i]!='\0';i++)
       sum+=(num[i]-'0');
       flag=0;
      for(i=0;num[i]!='\0';i++)
      {
        a=num[i]-'0';
        b=sum-a;
        if(b%3==0)
        {flag=1;num[i]='7';break;}
      }
      printf("Case %d: ",kas++);
      if(!flag)
        printf("T");
      else
      {
          cnt=0;
      for(i=0;num[i]!='\0';i++)
      {
        a=num[i]-'0';
        if(a%3==0)
         cnt++;
      }
      if(cnt%2==0)
       printf("S");
      else
        printf("T");
      }
      printf("\n");
    }
    return 0;
}
