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
qi q1,q2;
char str[2000][2000];
bool vis[1006][1006];
int n,m;

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

void bfs()
{
	int a,b,c,d,i;
	while(!q1.empty())
	{
		a=q1.front();b=q2.front();
		q1.pop();q2.pop();
		for(i=0;i<4;i++)
		{
			c=a+xx[i];d=b+yy[i];
			if(c>=0&&d>=0&&c<m&&d<n&&!vis[c][d]&&str[c][d]==str[a][b])
			{
				vis[c][d]=1;
				q1.push(c);q2.push(d);
			//	printf("%d %d\n",c,d);
			}
		}

	}
}
int main()
{
    int k,i,j,a,b,kas=0;
    while(gets(str[0]))
    {
    memset(vis,0,sizeof(vis));
      m=1;
      while(1){
       gets(str[m++]);
       if(str[m-1][0]>='a'&&str[m-1][0]<='z')
        continue;
       sscanf(str[m-1],"%d",&k);
       m--;
       break;
       }
     //  printf("%d\n",k);
       n=strlen(str[m-1]);
       bool chh=0;
       while(k--)
       {
                 chh=1;
        scanf("%d %d",&a,&b);
         q1.push(a-1);q2.push(b-1);
         vis[a-1][b-1]=1;
        // printf("%d %d %c\n",m,n,str[a-1][b-1]);
       }
       if(chh)
       getchar();
       bfs();
       
       bool row[3000]={0};
       for(i=0;i<m;i++){
        k=0;
        for(j=0;j<n;j++)
         if(!vis[i][j])
         {
          vis[i][j]=1;
          str[i][k]=str[i][j];
          vis[i][k]=0;
          k++;
          }
          if(!k)
           row[i]=1;
          }
      printf("Test case #%d:\n",++kas);

       for(i=0;i<m;i++){
       bool flag=0;
        for(j=0;j<n;j++)
         if(!vis[i][j]){
         bool yes=0;
         for(k=i+1;k<m;k++)
          if(!row[k]&&vis[k][j]){
           vis[k][j]=0,str[k][j]=str[i][j],yes=1;break;}
           if(yes)
            continue;
            flag=1;
          printf("%c",str[i][j]);}
         if(flag)
          printf("\n");
          }

    }
    return 0;
}
