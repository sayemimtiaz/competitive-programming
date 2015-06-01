#include<stdio.h>
#define INF 2147483647
int main()
{
    long kase,sh,sm,k,min,i,h,m,a,kas=1;
    char str[1000];
    scanf("%ld",&kase);
    getchar();
    while(kase--)
    {
        gets(str);
        sscanf(str,"%ld %ld:%ld",&k,&sh,&sm);
        sm+=sh*60;
        min=INF;
        for(i=0;i<k;i++)
        {
          gets(str);
          sscanf(str,"%ld:%ld %ld",&h,&m,&a);
          m+=h*60;
          if(m>=sm)
          {m+=a;m-=sm;}
          else
           m=1440-(sm-m)+a;
          if(m<min)
           min=m;
        }
        printf("Case %ld: %ld\n",kas++,min);
    }
    return 0;
}
