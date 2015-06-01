#include<stdio.h>
int main()
{
    int S[12000],pS,i,L,H,R;
    bool flag=0;
    for(i=1;i<=10000;i++)
     S[i]=-1;
    while(~scanf("%d %d %d",&L,&H,&R))
    {
      for(i=L;i<R;i++)
       if(S[i]<H)
        S[i]=H;
      if(S[i]==-1)
       S[i]=0; 
    }
    for(i=1;i<=10000;i++)
     if(S[i]!=-1)
     {
       if(!flag)
       {
       flag=1;
       printf("%d %d",i,S[i]);
       pS=S[i];
       }
       else if(pS!=S[i])
       {
       printf(" %d %d",i,S[i]);
       pS=S[i];
       }
     }
     printf("\n");
    return 0;
}
