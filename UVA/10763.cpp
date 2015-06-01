#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000009
long n,list1[SIZE],list2[SIZE];
int main()
{
	long i,a,b,s,p;
	while(scanf("%ld",&n)==1&&n)
	{
        memset(list1,0,sizeof(list1));
        memset(list2,0,sizeof(list2));
        p=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld %ld",&a,&b);
			s=a+b;
			if(a<b)
			{
               if(list2[s])
               {
                list2[s]--;
                p++;
                }
                else
                list1[s]++;
            }
            else
            {
                if(list1[s])
               {
                list1[s]--;
                p++;
                }
                else
                list2[s]++;
            }
         }
		if((2*p)!=n)
			printf("NO");
		else
			printf("YES");
		printf("\n");
	}
	return 0;
}
