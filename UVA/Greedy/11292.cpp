#include<cstdio>
#include<algorithm>
using namespace std;
int D[20009],K[20009]; 
int main()
{
    int i,j,sum,n,m;
    bool doit;
    while(scanf("%d %d",&n,&m)&&(n||m))
    {
      for(i=0;i<n;i++)
       scanf("%d",&D[i]);
      for(i=0;i<m;i++)
       scanf("%d",&K[i]);
      if(n>m)
      {printf("Loowater is doomed!\n");continue;}
      sort(D,D+n);
      sort(K,K+m);
      doit=1;
      for(i=0,j=0,sum=0;i<n;i++)
      {
            bool cn=0;
            for(;j<m;j++)
             if(K[j]>=D[i])
             {cn=1;sum+=K[j];j++;break;}
      if(!cn)
       {doit=0;printf("Loowater is doomed!\n");break;}
      }
      if(doit)
       printf("%d\n",sum);
    }
    
    return 0;
}
