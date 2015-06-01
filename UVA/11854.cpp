#include<stdio.h>
int main()
{
	long double a[3],t;
	int i,j;
	while(1)
	{
		scanf("%Lf %Lf %Lf",&a[0],&a[1],&a[2]);
		if(a[0]==0&&a[1]==0&&a[2]==0)
			break;
		for(i=0;i<3;i++)
			for(j=i+1;j<3;j++)
				if(a[i]>a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
		t=(a[0]*a[0]+a[1]*a[1]);
		if(t==(a[2]*a[2]))
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}
