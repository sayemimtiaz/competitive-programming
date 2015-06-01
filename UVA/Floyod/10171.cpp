#include<stdio.h>
#define INF 200000000
long shah[200][200],migu[200][200];
void init()
{
	long i,j;
	for(i='A';i<='Z';i++)
	{
		for(j='A';j<='Z';j++)
		{ 
			shah[i][j]=INF;
			migu[i][j]=INF;
		}
			shah[i][i]=0;
			migu[i][i]=0;
    }
}
int main()
{
	long N,cost,i,j,k,keep;
	char city1,city[50000],city2,who,type;
	while(scanf("%ld",&N)==1&&N)
	{
		init();
		for(i=0;i<N;i++)
		{
			getchar();
			scanf("%c %c %c %c %ld",&who,&type,&city1,&city2,&cost);
		    if(who=='M')
		    {
                if(migu[city1][city2]>cost)
				migu[city1][city2]=cost;
				if(type=='B'&&migu[city2][city1]>cost)
					migu[city2][city1]=cost;
		    }
		    else
		    {
                if(shah[city1][city2]>cost)
                	shah[city1][city2]=cost;
			if(type=='B'&&shah[city2][city1]>cost)
				shah[city2][city1]=cost;
            }
		}
		getchar();
		scanf("%c %c",&city1,&city2);
		for(k='A';k<='Z';k++)
			for(i='A';i<='Z';i++)
				for(j='A';j<='Z';j++)
				{
					keep=shah[i][k]+shah[k][j];
					if(keep<shah[i][j])
						shah[i][j]=keep;
					keep=migu[i][k]+migu[k][j];
					if(keep<migu[i][j])
						migu[i][j]=keep;
				}
		keep=INF;
		k=0;
		for(i='A';i<='Z';i++)
		{
			if(shah[city1][i]<INF&&migu[city2][i]<INF)
			{
				if(keep>(shah[city1][i]+migu[city2][i]))
				{
					k=0;
					city[k++]=i;
					keep=shah[city1][i]+migu[city2][i];
				}
				else if(keep==(shah[city1][i]+migu[city2][i]))
					city[k++]=i;
			}
		}
	   if(keep>=INF)
			printf("You will never meet.");
		else
		{
			printf("%ld",keep);
			for(i=0;i<k;i++)
			printf(" %c",city[i]);
		}
		printf("\n");

	}
	return 0;
}
