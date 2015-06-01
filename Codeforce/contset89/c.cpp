#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<cctype>
#include<string>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define pb push_back
#define mem(x) memset(x,sizeof(x),0)
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
  bool f[200]={0};
  int n,k;
 char ss,ori[50000],str[50000],nss[50000],ns[50000];
inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

void check1()
{
     int i,j;
      for(i=0,j=0;i<n;i++)
      {
        if(j<k&&f[ori[i]]){
         nss[i]=ss;j++;}
        else
         nss[i]=ori[i];    
      }
       nss[i]='\0';
}
void check()
{
     int i,j;
      for(i=0,j=0;i<n;i++)
      {
        if(j<k&&f[ori[i]]){
         ns[i]=ss;j++;}
        else
         ns[i]=ori[i];    
      }
       ns[i]='\0';
}
int main()
{
    int i,j,a,b,min,sum,t1,its,l,tt;
   
    while(scanf("%d %d",&n,&k)==2)
    {
    
      scanf("%s",str);
      strcpy(ori,str);
      sort(str,str+n);
      sum=0;min=INT_MX;
      /*for(i=0;i<k;i++)
       sum+=(str[i]-'0');
      t1=sum/k;*/
      sum=0;
      for(i=0;i<=9;i++)
      {
       sum=0;
      for(j=0;j<k;j++)
      {
          a=(i-(str[j]-'0'));
          if(a<0)a=-a;
         sum+=a;
      }
         if(min>sum)
         {
          min=sum;ss=i+'0';
          for(j=0;j<=9;j++)
           f[j+'0']=0;
           for(j=0;j<k;j++)
            f[str[j]]=1;
           check();
          }
          else if(min==sum)
          {
          for(j=0;j<=9;j++)
           f[j+'0']=0;
           for(j=0;j<k;j++)
            f[str[j]]=1;
           check1();
           if(strcmp(nss,ns)<0)
            strcpy(ns,nss);
          }
      
      }
   
      /*sum=0;
    for(j=0,i=n-1;i>=0&&j<k;i--,j++)
       sum+=(str[i]-'0');
      t1=sum/k;*/
      sum=0;
      for(i=0;i<=9;i++)
      {
       sum=0;
      for(l=0,j=n-1;l<k&&j>=0;j--,l++){
          a=(i-(str[j]-'0'));
          if(a<0)a=-a;
         sum+=a;
         }
         if(min>sum)
         {
          min=sum;ss=i+'0';
          for(j=0;j<=9;j++)
           f[j+'0']=0;
          for(j=0,tt=n-1;tt>=0&&j<k;tt--,j++)
        f[str[tt]]=1;
        check();
        }
        else if(min==sum)
         {
          min=sum;ss=i+'0';
          for(j=0;j<=9;j++)
           f[j+'0']=0;
          for(j=0,tt=n-1;tt>=0&&j<k;tt--,j++)
        f[str[tt]]=1;
        check1();
            if(strcmp(nss,ns)<0)
            strcpy(ns,nss);
        }
        
      }
      // printf("%d %d %c\n",min,its,ss);
      if(min==INT_MX)
       min=0;
      printf("%d\n",min);

      printf("%s\n",ns);
    }
    return 0;
}
