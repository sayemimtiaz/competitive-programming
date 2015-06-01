#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXX 10009
long L1[MAXX],L2[MAXX];
int main()
{
    long N,M,kase,i,j,k,removed;
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld %ld",&N,&M);
      for(i=1;i<=N;i++)
       scanf("%ld",&L1[i]);
      for(i=1;i<=M;i++)
       scanf("%ld",&L2[i]);
      sort(L1+1,L1+N+1);
      sort(L2+1,L2+M+1);
      i=j=1;
      removed=0;
      while(i<=N||j<=M)
      {
        if(i<=N&&j<=M)
        {
        if(L1[i]==L2[j])
        {i++;j++;}
        else if(L1[i]>L2[j])
        {
          j++;
          for(k=1;j<=M&&L1[i]>L2[j];k++,j++);
          removed+=k;
          if(j<=M&&L1[i]<L2[j])
          { removed++;i++;}
           else if(j>M)
          {removed++;i++;}
          else
          {i++;j++;}
        }
        else
        {
          i++;
          for(k=1;i<=N&&L1[i]<L2[j];k++,i++);
          removed+=k;
          if(i<=N&&L1[i]>L2[j])
          { removed++;j++;}
          else if(i>N)
          {removed++;j++;}
          else
          {i++;j++;}
        }
        }
        else if(i>N)
          {removed+=(1+M-j);break;}
        else
        { removed+=(1+N-i);break;}
      } 
      printf("%ld\n",removed);
    }
    return 0;
}
