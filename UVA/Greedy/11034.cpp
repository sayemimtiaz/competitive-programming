#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    vector<int>v1,v2;
    int kase,i,j,x,y,cross,sum,L,M,a;
    bool bank;
    char s[100];
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&L,&M);
      L*=100;
      for(i=0;i<M;i++)
      {
        scanf("%d %s",&a,&s);
        if(s[0]=='l')
         v1.push_back(a);
        else
         v2.push_back(a);
      }
      x=v1.size();y=v2.size();
      i=j=0;bank=1;cross=0;int cnt=0;
      while(i<x||j<y)
      {
        if(bank)
        {
          sum=0;bank=0;
          for(;i<x;i++)
          {
            sum+=v1[i];
            if(sum>L)
            break;
        
          }
        }
        else
        {
          sum=0;bank=1;
          for(;j<y;j++)
          {
            sum+=v2[j];
            if(sum>L)
            break;
          }
        }
        cross++;
      }
      printf("%d\n",cross);
      v1.clear();v2.clear();
    }
                 
}
