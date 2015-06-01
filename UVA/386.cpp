#include<stdio.h>
long cub(long a)
{
	return a*a*a;
}
int main()
{
	long i,j,k,l;
	float s,e;
	for(i=2;i<=200;i++)
	{
		bool t[10000]={0};
		for(j=2;j<=200;j++)
		{
			for(k=2;k<=200;k++)
			{
				for(l=2;l<=200;l++)
				{
					if((!t[j]||!t[k]||!t[l])&&(cub(i)==cub(j)+cub(k)+cub(l)))
					{
						t[j]=t[k]=t[l]=1;
						printf("Cube = %ld, Triple = (%ld,%ld,%ld)\n",i,j,k,l);
						break;
					}
					else if(cub(i)<cub(j)+cub(l)+cub(k))
						break;
				}
			}
		}
	}
	return 0;
}