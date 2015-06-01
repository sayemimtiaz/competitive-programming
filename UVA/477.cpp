#include<stdio.h>
int main()
{
	 double x1[100],x2[100],y1[100],y2[100],x3[100],y3[100],r[100];
	long i,j,count,n,k=0,p;
   double x,y,p1;
	j=0;
	char ch[10000];
	while(1)
	{
		ch[j]=getchar();
		if(ch[j]=='*')
			break;
		if(ch[j]=='r')
		{
			scanf("%lf %lf %lf %lf",&x1[j],&y1[j],&x2[j],&y2[j]);
		}
		else
		{
			scanf("%lf %lf %lf",&x3[j],&y3[j],&r[j]);
		}
		j++;
		getchar();
	}
	long h=1;
    while(1)
	{
		scanf("%lf %lf",&x,&y);
		if(x==9999.9&&y==9999.9)
			break;
		count=0;
			k=0;
	      n=0;
		bool f=0;
		for(i=0;i<j;i++)
		{
			if(ch[i]=='r')
			{
			if((x>x1[i]&&x<x2[i])&&(y<y1[i]&&y>y2[i]))
			{
				f=1;
				printf("Point %ld is contained in figure %ld\n",h,i+1);
			}
			}
			else if(ch[i]=='c')
			{
				p1=(((x-x3[i])*(x-x3[i]))+((y-y3[i])*(y-y3[i])));
				if(p1<(r[i]*r[i]))
				{
					f=1;
				    printf("Point %ld is contained in figure %ld\n",h,i+1);
				}
			}
		}
		if(!f)
			printf("Point %ld is not contained in any figure\n",h);
      	h++;
	}
	return 0;
}