#include<stdio.h>
#include<string.h>
#define INF 114748364
long q[200][200];
int main()
{
	long kase,kas=1,u,v,c,n,e,i,j,k,cur,min;
	scanf("%ld",&kase);
	while(kase--)
	{
        scanf("%ld %ld",&n,&e);
	   for(i=1;i<=n;i++)
		 for(j=1;j<=n;j++)
		     q[i][j]=INF;
      for(i=1;i<=e;i++)
      {
        scanf("%ld %ld %ld",&u,&v,&c);
        if(q[u][v]>c)
        {
         q[u][v]=c; 
         q[v][u]=c;
         }
      }
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				if(q[j][k]>(q[j][i]+q[i][k]))
						q[j][k]=q[j][i]+q[i][k];
	min=INF;
	for(i=6;i<=n;i++)
	{
        if(q[1][i]==q[2][i]&&q[2][i]==q[3][i]&&q[3][i]==q[4][i]&&q[4][i]==q[5][i]&&q[3][i]!=INF)
        {
            cur=-100;
            for(j=1;j<=n;j++)
             {
               if(q[i][j]==INF)
               {cur=-100;
                break;}
             if(i!=j&&cur<q[i][j])
               cur=q[i][j];
               }
            if(min>cur&&cur!=-100)
             min=cur;
        }
    }
    
	printf("Map %ld: ",kas++);
	if(min!=INF)
	 printf("%ld\n",min);
    else
     printf("-1\n");
    }
		return 0;
	}                                                                                                                                                                                                                                                                                     
