#include<stdio.h>
int main()
{
	long double n,x1,y1,x2,y2,hole_x[1000],hole_y[1000],d1,d2;
	long i,h=0;
	bool flag;
	while(scanf("%Lf",&n)==1)
	{
		flag=0;
		scanf("%Lf %Lf %Lf %Lf",&x1,&y1,&x2,&y2);
		for(i=0;i<n;i++)
			scanf("%Lf %Lf",&hole_x[i],&hole_y[i]);
		for(i=0;i<n;i++)
		{
			d1=(((x1-hole_x[i])*(x1-hole_x[i])+(y1-hole_y[i])*(y1-hole_y[i])));
			d2=(((x2-hole_x[i])*(x2-hole_x[i])+(y2-hole_y[i])*(y2-hole_y[i])));
			d2=d2/4;
			if(d2-d1>=0)
			{
				flag=1;
				printf("The gopher can escape through the hole at (%0.3Lf,%0.3Lf).",hole_x[i],hole_y[i]);
				break;
			}
		}
		if(flag==0)
			printf("The gopher cannot escape.");
		printf("\n");
	}
	return 0;
}

