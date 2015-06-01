#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int>v1,v2;
    int kase,i,j,taken,x,y,n,a,prev;
    bool take;
    scanf("%d",&kase);
    while(kase--)
    {
      v1.clear();v2.clear();
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
        scanf("%d",&a);
        if(a>0)
         v1.push_back(a);
        else
          v2.push_back(-a);
      }
      x=v1.size();y=v2.size();
      if(x==0&&y==0)
      { printf("0\n");continue;}
      if(x==0||y==0)
      { printf("1\n");continue;}
      sort(v1.begin(),v1.end());
      sort(v2.begin(),v2.end());
      i=x-1;j=y-1;taken=1;
      if(v1[i]>v2[j])
        take=1,prev=v1[i],i--;
      else
        take=0,prev=v2[j],j--;
        int cnt=0;
      while(i>=0||j>=0)
      {
                      //printf("%d %d %d %d\n",prev,take,i,j);
        if(take)
        {
        for(;j>=0;j--) 
          if(v2[j]<prev)
          {
            take=0,prev=v2[j];j--;
            break;
          }
          if(take)
           break;
        }
        else
        {
            for(;i>=0;i--) 
          if(v1[i]<prev)
          {
            take=1,prev=v1[i];i--;
            break;
          }
          if(!take)
           break;
        }
        taken++;
      }
      printf("%d\n",taken);
    }
    return 0;
}

