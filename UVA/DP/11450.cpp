#include<stdio.h>
/*This problem is a kinda 0-1Knapsack like problem.But here No weight is given rather only price is
given.I used price both as weight and price.Another varaint from 0-1knapsack is here you'll be given
products as bundle.Under which several model of same product is given.So,A bundle means a single product.
Other variant are,unlike Knapsack you must take at least one element form each bundle to maximze the item taken which
won't exceed M.To do this I omiited p[i-1][j] of original knapsack.Because it means skipping cuurent item.But
here u'll need at least one item from each bundle.And other marginal change also brought.Look at the code below
to detect this changes.*/
struct product
{
       long price[30];
       long size;
}P[30];
long p[500][500];
int main()
{
	long m,n,c,i,j,k,w2,w3,kase;
	scanf("%ld",&kase);
	while(kase--)
	{
	scanf("%ld %ld",&m,&c);
	for(i=1;i<=c;i++)
	{
        scanf("%ld",&P[i].size);
        for(j=1;j<=P[i].size;j++)
		   scanf("%ld",&P[i].price[j]);
    }
	for(i=0;i<=m;i++)
		p[0][i]=0;
	for(i=0;i<=c;i++)
		p[i][0]=0;
	for(i=1;i<=c;i++)
	{
		for(j=1;j<=m;j++)
		{
			if((P[i].price[1]<=j&&i==1)||(P[i].price[1]<j&&p[i-1][j-P[i].price[1]]))
            {w2=P[i].price[1]+p[i-1][j-P[i].price[1]];}
            else
             w2=0;
			for(k=2;k<=P[i].size;k++)
			{
              if((P[i].price[k]<=j&&i==1)||(P[i].price[k]<j&&p[i-1][j-P[i].price[k]]))
              {w3=P[i].price[k]+p[i-1][j-P[i].price[k]];}
              else
              w3=0;
              if(w2<w3)
              {w2=w3;}   
            }
			p[i][j]=w2;
		}
	} 
    if(p[c][m])
	printf("%ld\n",p[c][m]);
    else
    printf("no solution\n");
   }
	return 0;
}
