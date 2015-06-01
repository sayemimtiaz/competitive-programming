#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define INF 114748367
#define MAXS 1009
struct P
{
	long x,y;
	long cst;
}Q[MAXS*MAXS];
typedef vector<long>vi;
bool block[MAXS][MAXS],visit[MAXS][MAXS];
long d[MAXS][MAXS];
long qsize,R,C;
void heapify(long lrg)
{
	P temp;
	long p,l,r;
	p=lrg;l=2*lrg+1;r=l+1;
	if(l<qsize&&Q[l].cst<Q[p].cst)
		p=l;
	if(r<qsize&&Q[r].cst<Q[p].cst)
		p=r;
	if(p!=lrg)
	{
		temp=Q[p];
		Q[p]=Q[lrg];
		Q[lrg]=temp;
		heapify(p);
	}
}
void insert(long c,long xx,long yy,long lrg)
{
	while(lrg>0&&Q[lrg/2].cst>c)
	{
		Q[lrg]=Q[lrg/2];
		lrg=lrg/2;
	}
	Q[lrg].x=xx;Q[lrg].y=yy;Q[lrg].cst=c;
	qsize++;
}
void dijkstra(long Sx,long Sy)
{
     int xx[]={0,0,1,-1};
     int yy[]={1,-1,0,0};
     long i,j,ux,uy,vx,vy;
     for(i=0;i<R;i++)
      for(j=0;j<C;j++)
		{visit[i][j]=0;d[i][j]=INF;}
	d[Sx][Sy]=0;
	Q[0].x=Sx;Q[0].y=Sy;
    Q[0].cst=0;
	qsize=1;
	while(qsize)
	{
		ux=Q[0].x;uy=Q[0].y;
		Q[0]=Q[qsize-1];
		heapify(0);
		qsize--;
		visit[ux][uy]=1;
		for(i=0;i<4;i++)
		{
			vx=ux+xx[i];vy=uy+yy[i];
			if(vx<0||vy<0||vx>=R||vy>=C||block[vx][vy])
			 continue;
			if(d[vx][vy]>(1+d[ux][uy]))
			{
				d[vx][vy]=1+d[ux][uy];
				if(!visit[vx][vy])
					insert(d[vx][vy],vx,vy,qsize);
				
			}
		}
	}
}
int main()
{
	long Sx,Sy,Dx,Dy,n,e,u,i,v,c,kase,B;
	while(scanf("%ld %ld",&R,&C)&&(R||C))
	{
     scanf("%ld",&B);
	 while(B--)
	 {
		scanf("%ld %ld",&u,&e);
		while(e--)
	    {
           scanf("%ld",&v);
           block[u][v]=1;
        }
     }
	 scanf("%ld %ld %ld %ld",&Sx,&Sy,&Dx,&Dy);
	 dijkstra(Sx,Sy);
	 printf("%ld\n",d[Dx][Dy]);
	 memset(block,0,sizeof(block));
    }
	return 0;
}
