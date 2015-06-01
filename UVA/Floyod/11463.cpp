#include<stdio.h>
#include<string.h>	
 long q[500][500];
 int imin(const int tl, const int tr)
{
    return (tl == 0 || tl > tr)? tr : tl;
}

int main()
{
	bool f;
	long num_node,test,h,i,j,k,b,c,s,w,max,edge;
	h=1;
	scanf("%ld",&test);
	while(test--)
	{
	scanf("%ld %ld",&num_node,&edge);
	memset(q,0,sizeof(q));
	for(i=0;i<edge;i++)
	{
		scanf("%ld %ld",&b,&c);
		q[b][c]=q[c][b]=1;
	}
	scanf("%ld %ld",&s,&c);

	for(k=0;k<num_node;k++)
	{
		for(i=0;i<num_node;i++)
		{
			for(j=0;j<num_node;j++)
			{
				    if(q[i][k] && q[k][j])
                     q[i][j] = imin(q[i][j],q[i][k] + q[k][j]);
			}
		
		}
	}
	for(i=0;i<num_node;i++)
		q[i][i]=0;
	f=1;
		for(i=0;i<num_node;i++)
		{
				w=q[s][i]+q[i][c];

				if(f)
				{
					f=0;
					max=w;
				}
				else if(w>max)
					max=w;
			
			
		}
		printf("Case %ld: %ld\n",h++,max);
		}
		return 0;
	}



