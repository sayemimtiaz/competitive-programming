#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define i64 long long
using namespace std;

vector<i64>key[9000],fr[9000];
i64 a[6000];

void insert(i64 ky,i64 pos)
{
    i64 siz,i;  
     siz=key[pos].size();
     for(i=siz-1;i>=0;i--)
      if(ky==key[pos][i])
      { fr[pos][i]++;return;}
     key[pos].push_back(ky),fr[pos].push_back(1);
}

i64 find(i64 ky,i64 pos)
{
    i64 siz,i;
   siz=key[pos].size();
     for(i=siz-1;i>=0;i--)
      if(ky==key[pos][i])
      return fr[pos][i];
       return 0;
}

int main()
{
    i64 n,i,j,k,res,ss;
    while(scanf("%lld",&n)==1)
    {
      for(i=0;i<n;i++)
      {
       scanf("%lld",&a[i]);
       insert(a[i],a[i]%7927);
      }
      res=0;
      for(i=0;i<n;i++)
       for(j=i+1;j<n;j++)
       {
         ss=a[i]+a[j];
         //printf("%d\n",find(ss,ss%7927));
         res+=find(ss,ss%7927);
       }
       printf("%lld\n",res);
         for(i=0;i<8000;i++)
          key[i].clear(),fr[i].clear();
    }
    return 0;
}
