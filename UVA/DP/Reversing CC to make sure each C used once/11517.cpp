#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MIN(a,b) (a<b)?a:b
#define INF 100000
int v[120],d[210009];

int main()
{
	int n,i,j,k,a,kase;
	scanf("%d",&kase);
	while(kase--)
	{
	scanf("%d %d",&k,&n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	d[0]=0;
    for(i=12000;i>0;i--)
     d[i]=INF;
      
	for(i=0;i<n;i++)
       for(j=12000;j>=0;j--)
		if(d[j]<INF)
		 d[j+v[i]]=MIN(d[j+v[i]],1+d[j]);
    for(i=k;i<=12000;i++)
     if(d[i]<INF){
	printf("%d %d\n",i,d[i]);
	break;}
  }
	return 0;
}
 
