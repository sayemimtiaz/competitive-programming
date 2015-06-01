#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX(a,b) (a>b)?a:b
#define i64 double 
#define MAX_INT 2147483647

i64 memo[220];
char str[220];
int L;

i64 split(int i)
{
  if(memo[i]!=-1)
   return memo[i];
  int k,p,j,ss;
  i64 n,t,m,v;
  m=0; 
  if(str[i]=='0')
   m=split(i+1);
  else
  { 
  for(k=1;k<=10;k++)
  {
    if(i+k<=L)
    {
      for(p=k-1,n=0,j=i;j<(i+k);j++)
      {
        for(ss=1,v=1;ss<=p;ss++)v*=10;
       n+=((str[j]-'0')*v);p--;}
      if(n<=MAX_INT)
      {
        t=n+split(i+k);
        if(m<t)
        m=t;
      }
    }
  }
  }
  memo[i]=m;
  return m;
}

int main()
{
    int kase,i;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%s",&str);
      for(i=0;str[i]!='\0';i++)
       memo[i]=-1;
      L=i;
      for(i--;i<210;i++)
       memo[i]=-1;
      split(0);
      printf("%0.lf\n",memo[0]);
    }
    return 0;
}
