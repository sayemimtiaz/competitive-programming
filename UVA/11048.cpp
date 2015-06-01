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
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a

char P[10009][50];
int L[10009];
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
    int i,j,k,d,q,Ll,r,rr;
    char T[50];
    bool out,flag,flag1;
    scanf("%d",&d);
    for(i=0;i<d;i++)
     scanf("%s",P[i]),L[i]=strlen(P[i]);
    scanf("%d",&q);
    while(q--)
    {
      scanf("%s",T);
      Ll=strlen(T);
      out=true;rr=0;
      for(i=0;i<d;i++)
      {
        if(Ll==L[i])
        {
          flag=false;flag1=false;out=true;
          for(j=0;j<Ll;j++)
          if(P[i][j]==T[j])
           continue;
          else if(j+1<Ll&&P[i][j+1]!=T[j+1]&&T[j]==P[i][j+1]&&P[i][j]==T[j+1])
           {
             if(flag1==true||flag==true){out=false;
              break;}
             flag=true;
             j++;
           }
          else
          {
           if(flag==true||flag1==true){
          out=false;
           break;}
           flag1=true;
           }
          if(!rr&&out&&(flag||flag1))
            r=i,rr=1;
           else if(out==true&&flag==false&&flag1==false)
           { r=i;rr=2;break;}
        }
        else if(L[i]-Ll==1)
        {
        out=true;
          for(k=-1,j=0;j<Ll;j++)
          {
            flag=false;
            for(k++;k<L[i];k++)
             if(T[j]==P[i][k])
             {flag=true;break;}
            if(flag==false)
            {out=false; break;}
          }
          if(out&&!rr)
                     r=i,rr=3;
        }
        else if(Ll-L[i]==1)
        {
             out=true;
          for(k=-1,j=0;j<L[i];j++)
          {
            flag=false;
            for(k++;k<Ll;k++)
             if(T[k]==P[i][j])
             {flag=true; break;}
            if(flag==false)
            {out=false; break;}
          }
          if(out&&!rr)
          r=i,rr=4;
           
        }
      }
       if(rr==1)
      printf("%s is a misspelling of %s\n",T,P[r]);
      else if(rr==2)
      printf("%s is correct\n",T);
      else if(rr==3)
      printf("%s is a misspelling of %s\n",T,P[r]);
      else if(rr==4)
       printf("%s is a misspelling of %s\n",T,P[r]);
      else
        printf("%s is unknown\n",T);
    }
    return 0;
}
