#include<stdio.h>
#define size 100000
#define INF 32000
int r,c,sc,sd;
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int cost[205][205],cst[205][205];
int qx1[size],qy1[size],front,rear;
char array[205][205];
void bfs_fire(int x1,int y1)
{
	int i,a,b,f,d;
	front=0;
	qx1[0]=x1;qy1[0]=y1;cost[x1][y1]=0;rear=1;
	while(front!=rear)
	{
		a=qx1[front];b=qy1[front];front++;
		for(i=0;i<4;i++)
		{
			f=a+x[i];d=b+y[i];
			 if(f<0||d<0||f>=r||d>=c)
				 continue;
			if(array[f][d]=='.'&&(cost[a][b]+1)<cost[f][d])
			{
				cost[f][d]=cost[a][b]+1;
				qx1[rear]=f;qy1[rear++]=d;
			}
		}
	}
}
void bfs_joe()
{
	int i,a,b,f,d;
	while(front!=rear)
	{
		a=qx1[front];b=qy1[front];front++;
		for(i=0;i<4;i++)
		{
			f=a+x[i];d=b+y[i];
			 if(f<0||d<0||f>=r||d>=c)
				continue;
				if(array[f][d]=='.'&&(cst[a][b]+1)<cost[f][d])
				{
					array[f][d]='#';
					cst[f][d]=cst[a][b]+1;
						 qx1[rear]=f;qy1[rear++]=d;
				}
		}
	}
}
int main()
{
	int kase,i,j,si,sj,kas=0;
	scanf("%d",&kase);
	while(kase--)
	{
		scanf("%d %d",&r,&c);
		 for(i=0;i<r;i++)
                scanf("%s",array[i]);
            for(i=0;i<=r;i++)
                for(j=0;j<=c;j++)
                    cost[i][j]=cst[i][j]=INF;
            for(i=0;i<r;i++)
                for(j=0;j<c;j++)
                {
                    if(array[i][j]=='J')
					{si=i;sj=j;}
                    if(array[i][j]=='F')
					{bfs_fire(i,j);}
                }
		front=rear=0;
		qx1[rear]=si;qy1[rear++]=sj;cst[si][sj]=0;bfs_joe();
		si=INF;
		   for(i=0;i<r;i++)
		   {
            for(j=0;j<c;j++)
            {
                if((i==0 || j==0 || i==r-1 || j==c-1) && cst[i][j] < si )
                    si=cst[i][j];
            }
		   }
		   printf("Case %d: ",++kas);
		if(si==INF)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",si+1);
			
	}
	return 0;
}
