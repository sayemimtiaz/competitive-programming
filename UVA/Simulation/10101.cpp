#include<stdio.h>
#include<string.h>
int main()
{
	int match[7]={9,10,11,12,13,14,15};
	int val[7]={2,3,4,5,6,7,8};
	char bangla[100];
	int pr,i,j,len,a,kas=1;
	bool flag;
	while(gets(bangla))
	{
        pr=-1;flag=0;
        for(i=0;bangla[i]=='0';i++);
        strcpy(bangla,&bangla[i]);
		len=strlen(bangla);
		printf("%4d. ",kas++);
	for(i=len;i>=1;i--)
	{
		a=i;
		if(i>8)
		{
			for(j=0;j<7;j++)
				if(match[j]==i)
				{
					a=val[j];
					break;
				}
		}
		switch(a)
		{
		case 1:
			
            a=len-i-1;
			if(a>=0&&bangla[a]!='0')
			{if(flag)printf(" ");flag=1;
			 printf("%c%c",bangla[a],bangla[len-i]);}
            else if(bangla[len-i]!='0')
            {if(flag)printf(" ");flag=1;
			printf("%c",bangla[len-i]);}
			pr=1;
			break;
 		case 3:
            if(bangla[len-i]!='0')
            {if(flag)printf(" ");flag=1;
			printf("%c shata",bangla[len-i]);}
			else if(pr<=3)
			printf(" shata");
			pr=3;
			break;
		case 4:
			
            a=len-i-1;
			if(a>=0&&bangla[a]!='0')
			{if(flag)printf(" ");flag=1;
			 printf("%c%c hajar",bangla[a],bangla[len-i]);}
		    else if(bangla[len-i]!='0')
		    {if(flag)printf(" ");flag=1;
			printf("%c hajar",bangla[len-i]);}
			else if(pr<=4)
			printf(" hajar");
			pr=4;
			break;
		case 6:
			
            a=len-i-1;
			if(a>=0&&bangla[a]!='0')
			{if(flag)printf(" ");flag=1;
			 printf("%c%c lakh",bangla[a],bangla[len-i]);}
		    else if(bangla[len-i]!='0')
		    {if(flag)printf(" ");flag=1;
			printf("%c lakh",bangla[len-i]);}
			else if(pr<=6)
			printf(" lakh");
			pr=6;
			break;
		case 8:
			
            a=len-i-1;
			if(a>=0&&bangla[a]!='0')
			{if(flag)printf(" ");flag=1;
			 printf("%c%c kuti",bangla[a],bangla[len-i]);}
		    else if(bangla[len-i]!='0')
		    {if(flag)printf(" ");flag=1;
			printf("%c kuti",bangla[len-i]);}
			else if(pr<=8)
			printf(" kuti");
			pr=8;
			break;
		}
	}
	if(!flag)
	 printf("0");
	printf("\n");
	}
	return 0;
}


