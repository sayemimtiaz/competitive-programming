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
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 int
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

char F[600][30],S[600][30];
int f,s,C[600][600];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
inline dle dis(Point a,Point b)
{
  //Without sqrt()
  return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
}

inline int sep1(char *str)
{
     int i,j=0;
     char temp[100],ch;
     for(i=0;str[i]!='\0';i++){
       ch=tolower(str[i]);
       if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
        temp[j++]=str[i];
       else if(j)
       {
         temp[j]='\0';
         strcpy(F[f++],temp);
         j=0;
       }
       }
       if(j){
       temp[j]='\0';
       strcpy(F[f++],temp);}
       return i;
}
inline int sep2(char *str)
{
     int i,j=0;
     char temp[100],ch;
     for(i=0;str[i]!='\0';i++){
                                  ch=tolower(str[i]);
       if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
        temp[j++]=str[i];
       else if(j){
         temp[j]='\0';
         strcpy(S[s++],temp);
         j=0;
       }
       }
       if(j){
         temp[j]='\0';
         strcpy(S[s++],temp);}
       return i;
}
int main()
{
    int m,n,i,j,kas=0,h;
    char str[2000];
    
    while(gets(str))
    {
      f=s=0;
      m=sep1(str);
      gets(str);
      n=sep2(str); 
      printf("%2d. ",++kas);
      if(!m||!n){
       printf("Blank!\n");continue;}
       C[0][0]=0;
      for(i=1;i<=f;i++)
       for(j=1;j<=s;j++){
         h=strcmp(F[i-1],S[j-1]);
         if(!h)
            C[i][j]=1+C[i-1][j-1];
         else
          C[i][j]=MAX(C[i][j-1],C[i-1][j]);
          }
         printf("Length of longest match: %d\n",C[f][s]);
         mems(C);                                  
    }
    return 0;
}
