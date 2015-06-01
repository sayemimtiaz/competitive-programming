#include<stdio.h>
#include<stdlib.h>
long d[100000];
int main()
{
    long kase,kas=1,i,j,a,n,tmp,p,max;
    bool flag;
    scanf("%ld",&kase);
    while(kase--)
    {
       flag=1;
       scanf("%ld",&n);
       p=0;
       max=0;
       for(i=1;i<=n;i++)
        {
          scanf("%ld",&a);
          d[i]=a-p;
          if(d[i]<0)
           d[i]=-d[i];
          if(max<d[i])
           max=d[i];
          p=a;
        }
        for(i=max;;i++)
        {
          tmp=i;
          for(j=1;j<=n;j++)
          {
             if(d[j]<tmp)
              continue;
              if(d[j]>tmp)
               {tmp=-1;break;}
              tmp--;
          }
          if(tmp>=0)
           break;
        }
        printf("Case %ld: %ld\n",kas++,i);
    }
    return 0;
}
