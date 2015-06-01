#include<stdio.h>
#include<math.h>
int main()
{
	double x[4],y[4],mid_x,mid_y,s1,s2;
	int i,j;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF)
	{
		int a[30000]={0};
		for(i=0;i<4;i++)
		{
			for(j=i+1;j<4;j++)
			{
				if(x[i]==x[j]&&y[i]==y[j])
				{
					a[i]=1;
					a[j]=1;
					s1=x[i];
					s2=y[i];
					break;
				}
			}
		}
		for(i=0;i<4;i++)
		{
			for(j=i+1;j<4;j++)
			{
			   if(a[i]==0&&a[j]==0)
			   {
				   mid_x=(x[i]+x[j])/2;
				   mid_y=(y[i]+y[j])/2;
				   break;
			   }
			}
		}
		s1=(mid_x*2)-s1;
		s2=(mid_y*2)-s2;
		printf("%0.3lf %0.3lf\n",s1,s2);
	}
	return 0;
}


