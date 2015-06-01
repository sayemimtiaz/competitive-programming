#include<stdio.h>
#include<string.h>


int main()
{
    int N,S,T,fT,tT,i,j,size,afT,kas=1;
    while(scanf("%d %d %d",&S,&T,&N)&&(S||T||N))
    {
      size=((N+1)*T)+(N*S);
      fT=0;
      printf("Case %d:\n",kas++);
      for(i=0;i<size;i++)
      {
        if(fT*(S+T)==i)
        {
         fT++;
        for(tT=1;tT<=T;tT++){
         for(j=0;j<size;j++)
          putchar('*');
         putchar('\n');}
         i+=(T-1);
         continue;
        }
        afT=0;
        for(j=0;j<size;j++)
        {
          if(afT*(S+T)==j)
          {
            afT++;
            for(tT=1;tT<=T;tT++)
             putchar('*');
            j+=(T-1);
          }
          else putchar('.');
        }
        putchar('\n');
      }
      putchar('\n');
    }
    return 0;
}
