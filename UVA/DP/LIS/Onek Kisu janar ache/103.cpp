#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std; 
bool flag=0;
long K,N,par[100],d[100];
bool operator <(vector<long>ii,vector<long> jj)
{
     long i;
     for(i=0;i<N;i++)
      if(ii[i]>=jj[i])
        return false;
   return true;
   
}
void path(vector<vector<long> >v,long ii)
{
     if(ii==-1)
      return;
      path(v,par[ii]);
      if(!flag){flag=1;printf("%ld",v[ii][N]);}
      else
      printf(" %ld",v[ii][N]);
}
int main()
{
    long i,j,a,max;
    while(scanf("%ld %ld",&K,&N)==2)
    { 
         vector <vector<long> > v (K);
         for(i=0;i<K;i++)
         {
          for(j=0;j<N;j++)
          {
             scanf("%ld",&a);
             v[i].push_back(a);
          }
          sort(v[i].begin(),v[i].end());
          v[i].push_back(i+1);
         }
         sort(v.begin(),v.end());
         for(i=0;i<K;i++)
         {par[i]=-1;d[i]=1;}
         for(i=0;i<K;i++)
          for(j=i+1;j<K;j++)
           if(v[i]<v[j])
            if(d[i]+1>d[j])
            {
               d[j]=d[i]+1;
               par[j]=i;
            }
           flag=0;
          max=d[0];j=0;
          for(i=1;i<K;i++) 
           if(max<d[i])
          {max=d[i];j=i;}
          printf("%ld\n",max);
          path(v,j);
          printf("\n");
    }
    return 0;
}
