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
#define MX 60000
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

void Badd(char *first,char *sec)
{
  int i,hold=0,r;
  for(i=0;first[i]!='\0'&&sec[i]!='\0';i++)
  {
    r=hold+first[i]-'0'+sec[i]-'0';
    sec[i]=r%10+'0';
    hold=r/10;
  } 
  if(first[i]=='\0')
   for(;sec[i]!='\0';i++)
   {
    r=hold+sec[i]-'0';
    sec[i]=r%10+'0';
    hold=r/10;
   }
  else
  for(;first[i]!='\0';i++)
   {
    r=hold+first[i]-'0';
    sec[i]=r%10+'0';
    hold=r/10;
   }
   while(hold)
   {
     sec[i++]=hold%10+'0';
     hold/=10;
   }
   sec[i]='\0';
}
void Bmult(char *from,char *to,int A)
{
     int hold,i,r;
     for(hold=0,i=0;from[i]!='\0';i++)
     {
       r=hold+A*(from[i]-'0');
    //  printf("%c %d\n",from[i],r);
       to[i]=r%10+'0';
       hold=r/10;
     }
     while(hold)
     {
       to[i++]=hold%10+'0';
       hold/=10;
     }
     to[i]='\0';
   //  printf("\n%s %s %d\n",from,to,A);
}
int main()
{
    int n,A,i,j;
    char temp[MX],Ares[MX],res[MX];
    while(~scanf("%d %s",&n,temp))
    {
       sscanf(temp,"%d",&A);
       if(n==1){
        printf("%s\n",temp);continue;}
       for(j=0,i=strlen(temp)-1;i>=0;i--)
        Ares[j++]=temp[i];
       Ares[j]='\0'; 
       res[0]='0',res[1]='\0';
       for(i=1;i<=n;i++)
       {
         Bmult(Ares,temp,i);
         Badd(temp,res);
       // printf("%s %s\n",temp,res);
         Bmult(Ares,Ares,A);
       }
       for(i=strlen(res)-1;i>=0;i--)
        printf("%c",res[i]);
       printf("\n");
    }
    return 0;
}
