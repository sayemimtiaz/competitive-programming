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

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int main()
{
    char sstr[5000],fstr[5000],nstr[5000],str[5000];
    char ch[]={'l','u','c','k','y'};
    int i,j,n,m,l,kase,k,min,len,r,cnt;
    scanf("%d",&kase);
    while(kase--)
    {
     scanf("%s",str);
     strcpy(nstr,str);
     len=strlen(str);
     l=len/2;
     if(len%2)
      r=l+2;
     else
     r=l+1;
     sstr[len]='\0';
     min=INT_MX;
     bool ban[2000]={0};
     for(i=0;i<len-4;i++)
     {
       cnt=0;
       for(k=0,j=i;k<5;k++,j++)
       {
         if(nstr[j]!=ch[k])
          cnt++;
        ban[j]=1,nstr[j]=ch[k];
        }
        //printf("%s %d %d\n",nstr,l,r);
         if(len%2)
        sstr[l]=nstr[l];
       for(j=l-1,k=r-1;k<len;k++,j--){
          if(nstr[j]==nstr[k])
           sstr[j]=nstr[j],sstr[k]=nstr[k];
           else if(ban[j]&&ban[k])
           {cnt=INT_MX; break;}
           else if(ban[j])
               cnt++,sstr[j]=nstr[j],sstr[k]=nstr[j];
           else if(ban[k])
               cnt++,sstr[j]=nstr[k],sstr[k]=nstr[k];
          else if(nstr[j]>nstr[k])
           cnt++,sstr[j]=nstr[k],sstr[k]=nstr[k];
           else
             cnt++,sstr[j]=nstr[j],sstr[k]=nstr[j];
           }
       //  printf("%s %d\n",sstr,cnt);
       if(min>cnt)
        min=cnt,strcpy(fstr,sstr);
       else if(min==cnt&&strcmp(sstr,fstr)<0)
        strcpy(fstr,sstr);
       
       for(j=i;j<i+5;j++)
         ban[j]=0,nstr[j]=str[j];
     }
     if(min!=INT_MX)
      printf("%s %d\n",fstr,min);
     else
      printf("unlucky\n");
    }
    return 0;
}
