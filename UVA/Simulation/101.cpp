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
#define eps 0.00000000001

struct Pile
{ 
 int L[300];
 int S;
}P[30];
int m[26];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

void clr(int a,int b)
{
     int i,c;
     for(i=P[a].S-1;i>=0&&P[a].L[i]!=b;i--)
     {
      c=P[a].L[i];
      m[c]=c;
      P[c].L[P[c].S++]=c;
      }
     P[a].S=i+1;
}


void add(int a,int b,int c)
{
     int i,j;
     for(i=0;i<P[a].S&&P[a].L[i]!=b;i++);j=i;
     for(;i<P[a].S;i++)
       P[c].L[P[c].S++]=P[a].L[i],m[P[a].L[i]]=c;
     P[a].S=j;
}

int main()
{
    int i,j,n,s,a,b;
    char F[5000],S[5000],str[5000];
    while(gets(str))
    {
    sscanf(str,"%d",&n);
    for(i=0;i<n;i++)
      m[i]=i,P[i].L[0]=i,P[i].S=1;
    while(gets(str)&&str[0]!='q')
    {
      sscanf(str,"%s %d %s %d",F,&a,S,&b);
     //printf("%d %d %d\n",m[a],m[b],v[m[a]].size());
      if((m[a]==m[b])||!P[m[a]].S)
      continue;
      if(F[0]=='m')
      {
        if(S[3]=='o')
        {
          clr(m[a],a);
          clr(m[b],b);
          P[m[b]].L[P[m[b]].S++]=a;
          P[m[a]].S--;
          m[a]=m[b];
        }
        else
        {
            clr(m[a],a);
            P[m[b]].L[P[m[b]].S++]=a;
            P[m[a]].S--;   
            m[a]=m[b];
        }
      }
      else
      {
          if(S[3]=='o')
          {
            clr(m[b],b);
            add(m[a],a,m[b]);
          }
          else
              add(m[a],a,m[b]);
      }
      }
    for(i=0;i<n;i++)
    { 
      printf("%d:",i);
      for(j=0;j<P[i].S;j++)
       printf(" %d",P[i].L[j]);
      printf("\n");
    }
   }
    return 0;
}
