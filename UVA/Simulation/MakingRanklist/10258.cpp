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

int T[109][11];

struct Final
{
  int penalty;
  bool valid;
  int solved;
  int team;
}F[109];

bool cmp(Final a,Final b)
{
     if(a.solved!=b.solved)
     return (a.solved>b.solved);
     if(a.penalty!=b.penalty)
      return (a.penalty<b.penalty);
     return (a.team<b.team);
      
}
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
    int kase,a,b,c,i;
    char d;
    char str[1000];
    bool flag=0;
    scanf("%d",&kase);
    getchar();
    getchar();
    while(kase--)
    {
      for(i=0;i<103;i++)
       F[i].valid=0,F[i].team=i,F[i].solved=0,F[i].penalty=0;
     while(gets(str)&&str[0]!='\0')
     {
        sscanf(str,"%d %d %d %c",&a,&b,&c,&d);
        F[a].valid=1;
        if(d=='R'||d=='U'||d=='E'||T[a][b]==-1)
         continue; 
        if(d=='C')
        {
          F[a].penalty+=c+T[a][b];
          F[a].solved++;
          T[a][b]=-1;
        }
        else
          T[a][b]+=20;   
     }
     sort(F,F+102,cmp);
     if(flag)
     printf("\n");
     else
      flag=1;
     for(i=0;i<=102;i++)
      if(F[i].valid)
       printf("%d %d %d\n",F[i].team,F[i].solved,F[i].penalty);
      memset(T,0,sizeof(T));
    }
    return 0;
}
