#include<stdio.h>
#include<math.h>
long M[1200][12];
int main()
{
    long kase,i,j,C[1200],N,minM,day,CowDied,ToEat,LastDay,cnt;
    bool Removed,flag,Eaten[1200];
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld",&N);
      for(i=1;i<=N;i++)
      {
         Eaten[i]=0;
         scanf("%ld",&C[i]);
         for(j=1;j<C[i];j++)
            scanf("%ld",&M[i][j]);
         scanf("%ld",&M[i][0]);
      }
      cnt=0;
      day=0;CowDied=0;
      while(1)
      {
           minM=1000000000;
           day++;
           flag=0;
           for(j=1;j<=N;j++)
           {
            
             if(!Eaten[j])
             {
                if(minM>M[j][day%C[j]])
                {
                  minM=M[j][day%C[j]];
                  ToEat=j;
                  flag=1;
                }
                else if(minM==M[j][day%C[j]])
                 flag=0;
             }
           }
           if(flag)
           {
            Removed=true;
            LastDay=day;
            CowDied++;
            Eaten[ToEat]=1;
            cnt=0;
           }
           else
            cnt++;
           if(cnt==500)
            break;
      }
      if(!CowDied)
      LastDay=0;
      printf("%ld %ld\n",N-CowDied,LastDay);
    }
    return 0;
}
