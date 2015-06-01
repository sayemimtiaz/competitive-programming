#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define SIZE 10050
struct S
{
  long a,b,c;
}P[SIZE];
long rank[SIZE],par[SIZE],N;
bool cmp(S a,S b)
{
     return a.c>b.c;
}
void make_set()
{
     long i;
     for(i=0;i<N;i++)
     {
       rank[i]=0;
       par[i]=i;
     }
}
void link(long a,long b)
{
	if(rank[a]>rank[b])
		par[b]=a;
	else
	{
		par[a]=b;
		if(rank[a]==rank[b])
			rank[b]++;
	}
}
long find(long a)
{
	if(a!=par[a])
		par[a]=find(par[a]);
	return par[a];
}
int main()
{
    long kase,kas=1,M,i,j,x,y;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%ld %ld",&N,&M);
       make_set();
       for(i=0;i<M;i++)
           scanf("%ld %ld %ld",&P[i].a,&P[i].b,&P[i].c);
       sort(P,P+M,cmp);
       j=0;bool flag=0;
       for(i=0;i<M;i++)
       {
		x=find(P[i].a);y=find(P[i].b);
		if(x!=y)
		{
			link(x,y);
			j++;
			if(j==N-1)
			{
                      flag=1;
                       printf("Case #%ld: %ld\n",kas++,P[i].c);
                       break;
             }
		}
    }
		if(!flag)
		 printf("Case #%ld: %ld\n",kas++,P[0].c);
  	
    }
    return 0;
}
