#include<stdio.h>
#include<stdlib.h>
int main()
{
	long x1,y1,x2,y2;
	while(1)
	{
		scanf("%ld %ld %ld %ld",&x1,&y1,&x2,&y2);
		if(!x1&&!y1&&!x2&&!y2)
			break;
		if(x1==x2&&y1==y2)
			printf("0");
		else if(x1==x2||y1==y2||(abs(x1-x2)==abs(y1-y2)))
			printf("1");
		else
			printf("2");
		printf("\n");
	}
	return 0;
}