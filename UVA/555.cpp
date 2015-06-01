#include<stdio.h>
#include<string.h>
struct T
{
	char N[100][100];
	long index;
}gr[4];
char s[100][100];
char p[4]={'S','W','N','E'};

void srt(long i)
{
	char temp[100];
	long k,j;
	for(j=0;j<gr[i].index;j++)
	{
		
		for(k=j+1;k<gr[i].index;k++)
		{

			if((gr[i].N[j][0]=='D'&&gr[i].N[k][0]=='C')||(gr[i].N[j][0]=='S'&&gr[i].N[k][0]=='C')||(gr[i].N[j][0]=='H'&&gr[i].N[k][0]=='C')||(gr[i].N[j][0]=='S'&&gr[i].N[k][0]=='D')||(gr[i].N[j][0]=='H'&&gr[i].N[k][0]=='D')||(gr[i].N[j][0]=='H'&&gr[i].N[k][0]=='S'))
			{
					strcpy(temp,gr[i].N[j]);
                   	strcpy(gr[i].N[j],gr[i].N[k]);
	                strcpy(gr[i].N[k],temp);
			}
			else if(gr[i].N[j][0]==gr[i].N[k][0])
			{
				if((gr[i].N[j][1]=='J'&&gr[i].N[k][1]=='T')||(gr[i].N[j][1]=='Q'&&gr[i].N[k][1]=='T')||(gr[i].N[j][1]=='K'&&gr[i].N[k][1]=='T')||(gr[i].N[j][1]=='A'&&gr[i].N[k][1]=='T')||(gr[i].N[j][1]=='Q'&&gr[i].N[k][1]=='J')||(gr[i].N[j][1]=='K'&&gr[i].N[k][1]=='J')||(gr[i].N[j][1]=='A'&&gr[i].N[k][1]=='J')||(gr[i].N[j][1]=='K'&&gr[i].N[k][1]=='Q')||(gr[i].N[j][1]=='A'&&gr[i].N[k][1]=='Q')||(gr[i].N[j][1]=='A'&&gr[i].N[k][1]=='K'))
				{
										strcpy(temp,gr[i].N[j]);
                   		strcpy(gr[i].N[j],gr[i].N[k]);
	                strcpy(gr[i].N[k],temp);
					continue;
				}
				if((gr[i].N[j][1]>='A'&&gr[i].N[j][1]<='Z')&&(gr[i].N[k][1]>='A'&&gr[i].N[k][1]<='Z'))
					continue;
				else if(gr[i].N[j][1]>gr[i].N[k][1])
				{

					  					strcpy(temp,gr[i].N[j]);
                   		strcpy(gr[i].N[j],gr[i].N[k]);
	                strcpy(gr[i].N[k],temp);
				}
			}
		}
	}
}
void init()
{
	long i;
	for(i=0;i<4;i++)
		gr[i].index=0;
}
int main()
{
	char pos;
	long i,j,k,len;
	while(scanf("%c",&pos)==1&&pos!='#')
	{
	  getchar();
		init();
		for(i=0;i<2;i++)
			gets(s[i]);
		for(i=0;i<4;i++)
			if(pos==p[i])
				break;
			i++;
		for(k=0;k<2;k++)
		{
			len=strlen(s[k]);
			j=0;
			while(j<len)
			{
					if(i==4)
					i=0;
				gr[i].N[gr[i].index][0]=s[k][j];gr[i].N[gr[i].index][1]=s[k][j+1];gr[i].N[gr[i].index][2]='\0';
				gr[i].index++;
				j+=2;
				i++;
			
			}
		}
		for(i=0;i<4;i++)
		{
		srt(i);
			printf("%c:",p[i]);
			for(j=0;j<gr[i].index;j++)
				printf(" %s",gr[i].N[j]);
			printf("\n");
		}
	}
	return 0;
}

	