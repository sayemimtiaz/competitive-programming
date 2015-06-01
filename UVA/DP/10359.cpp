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
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
char m[255][60000];

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

void add(char *s1,char *s2,int kk)
{
	int i,k,sum,hold,j;
    k=0;
	for(i=0,j=0,hold=0;s1[i]!='\0'||s2[j]!='\0';)
	{
		if(s1[i]!='\0')
		sum=(s1[i++]-'0');
		 if(s2[j]!='\0')
		sum+=(s2[j++]-'0');
		sum+=hold;
		m[kk][k++]=sum%10+'0';
		hold=sum/10;
	}
	if(hold)
		m[kk][k++]=hold+'0';
	m[kk][k]='\0';
	

}
int main()
{
    int n,i;
     m[0][0]='1',m[0][1]='\0';
     m[1][0]='1',m[2][0]='3';
     m[1][1]='\0',m[2][1]='\0';
     for(i=3;i<=250;i++){
     add(m[i-2],m[i-2],i);
      add(m[i-1],m[i],i);}
      
    while(~scanf("%d",&n))
    {
     for(i=strlen(m[n])-1;i>=0;i--)
     printf("%c",m[n][i]);
     printf("\n");
    }
    return 0;
}
