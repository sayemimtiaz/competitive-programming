#include<stdio.h>

int P,E[30],j,counter[30],avg,i;
bool block[30];

void BackTrack(int how,int sum,int start)
{
  int k;
  if(how==j)
  {
    if(sum>=avg)
     return;
    for(k=0;k<P;k++)
     if(!block[k]&&(sum+E[k])>=avg)
      counter[k]++;
     return;
  }
  for(k=start;k<P;k++)
    if(!block[k])
    {
     block[k]=1;
     BackTrack(how+1,sum+E[k],k+1);
     block[k]=0;
     }
}

int main()
{
    int kase,Total,sum;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&P);
      sum=0;
      for(i=0;i<P;i++)
        scanf("%d",&E[i]),sum+=E[i],block[i]=0,counter[i]=0;
      avg=sum/2;if(avg*2!=sum)avg++;
        for(j=1;j<P;j++)
         BackTrack(0,0,0);
      for(i=0;i<P;i++)
      {
        if(E[i]>=avg)
         counter[i]++;
         printf("party %d has power index %d\n",i+1,counter[i]);
      }
      printf("\n");
    }
    return 0;
}
