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
int n,a[1000],c;


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
int par[SIZE],rank[SIZE];

void make_set()
{
	int i;
	for(i=1;i<=n;i++)
	{
		rank[i]=0;
		par[i]=i;
	}
}
void link(int a,int b)
{
	if(rank[a]>rank[b])
		par[b]=a;
	else
		par[a]=b;
	if(rank[a]==rank[b])
		rank[b]++;
}
int find(int a)
{
	if(a!=par[a])
    par[a]=find(par[a]);
	return par[a];
}
void sieve()
{
	int i,j;
	bool flag[1200]={0};
	a[0]=2;c=1;
	for(i=3;i<=1000;i+=2)
		if(flag[i]==0)
		{
			a[c++]=i;
			if(32>=i)
				for(j=i*i;j<=n;j+=2*i)
					flag[j]=1;
		}
}
int main()
{
    sieve();
    int l,i,j,k,x,y;
    char ch,str[1500],nstr[1500],ss;
    int fr[1500],sm;
    while(scanf("%s",&str)==1)
    {
      int fr[1000]={0};
      int fr1[1100]={0};
      
      for(i=0;str[i]!='\0';i++)
        fr[str[i]]++;
      n=i;
      make_set();
      for(i=0;a[i]<=n&&i<c;i++)
      {
        l=n/a[i];
        for(j=2;j<=l;j++)
        {
          if(a[i]*j<=n){
          x=find(a[i]),y=find(a[i]*j);
          if(x!=y)
           link(x,y);
         //  printf("c%d %d\n",x,y);
           }
        }
      }
      for(i=1;i<=n;i++){
       fr1[find(i)]++;
      // printf("%d %d\n",find(i),fr1[find(i)]);
       }
       bool flag=1;
      for(i=1;i<=n;i++)
      {
       if(fr1[i])
       {
         sm=INT_MX;
         rep(j,1,n)
          if(fr[str[j-1]]>=fr1[i]&&fr[str[j-1]]<sm)
           sm=fr[str[j-1]],ss=str[j-1];
        //  printf("%d %d %c\n",fr['x'],fr1[i],ch);
         if(sm==INT_MX){flag=0;break;}
         
         fr[ss]-=fr1[i],ch=ss;
         
         for(j=1;j<=n;j++)
          if(par[j]==i)
           nstr[j-1]=ch;
       }
      }
      
      nstr[n]='\0';
      if(flag==0)
       printf("NO\n");
      else
      printf("YES\n%s\n",nstr);
      
    }
    return 0;
}
