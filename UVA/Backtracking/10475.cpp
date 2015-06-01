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

struct Topic
{
  char str[100];
  int L;
}T[200];

bool P[200][200];
int t,S,a[200];

int cmp(const void *a, const void *b)
{
    Topic *x=(Topic*)a;
    Topic *y=(Topic*)b;
   if(x->L!=y->L)
    return (y->L-x->L);
   return (strcmp(x->str,y->str));
}

int pos(char *str)
{
    int b,e,m,h,L,j;
    for(j=0;str[j]!='\0';j++)
     str[j]=toupper(str[j]);
     L=j;
    b=0;e=t-1;
    while(b<=e)
    {
      m=(b+e)/2;
      if(T[m].L==L)
      {
        h=strcmp(T[m].str,str);
        if(!h)
         return m;
        if(h>0)
         e=m-1;
        else
         b=m+1;
      }
      else if(T[m].L>L)
       b=m+1;
      else
       e=m-1;
    }
}

void recur(int s,int d)
{
     int i,j;
     if(d==S)
     {
        printf("%s",T[a[0]].str);
        for(j=1;j<d;j++)
         printf(" %s",T[a[j]].str);
        printf("\n");
      return;
      }
     for(i=s;i<t;i++)
     {
       for(j=0;j<d;j++)
        if(P[a[j]][i])
         break;
       if(j==d)
       {
         a[d]=i;
         recur(i+1,d+1);      
       }
     }
}

int main()
{
    int kase,kas=1,p,j,i,a,b;
    char s1[1000],s2[1000];
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d %d",&t,&p,&S);
      for(i=0;i<t;i++)
      {
        scanf("%s",T[i].str);
        for(j=0;T[i].str[j]!='\0';j++)
         T[i].str[j]=toupper(T[i].str[j]);
        T[i].L=j;              
      }
      qsort(T,t,sizeof(Topic),cmp);
      while(p--)
      {
        scanf("%s %s",s1,s2);
        a=pos(s1);
        b=pos(s2);
        P[a][b]=P[b][a]=1;
      }
      printf("Set %d:\n",kas++);
      recur(0,0);
      printf("\n");
      memset(P,0,sizeof(P));
    }
    return 0;
}
