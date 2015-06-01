#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char res[2000][500];
int cmp(const void *a,const void *b)
{
	return (strcmp((char*)a,(char*)b));
}
int main()
{
	char map[100][20],str[1000];
	int i,j,k,N,F,len,save,a;
	map[1][1]='q';map[1][2]='a';map[1][3]='z';map[1][4]='\0';
	map[2][1]='w';map[2][2]='s';map[2][3]='x';map[2][4]='\0';
	map[3][1]='e';map[3][2]='d';map[3][3]='c';map[3][4]='\0';
	map[4][1]='r';map[4][2]='f';map[4][3]='v';map[4][4]='t';map[4][5]='g';map[4][6]='b';map[4][7]='\0';
	map[5][1]=' ';map[5][2]='\0';
	map[6][1]=' ';map[6][2]='\0';
	map[7][1]='y';map[7][2]='h';map[7][3]='n';map[7][4]='u';map[7][5]='j';map[7][6]='m';map[7][7]='\0';
	map[8][1]='i';map[8][2]='k';map[8][3]=',';map[8][4]='\0';
	map[9][1]='o';map[9][2]='l';map[9][3]='.';map[9][4]='\0';
	map[10][1]='p';map[10][2]=';';map[10][3]='/';map[10][4]='\0';
	while(scanf("%d %d",&F,&N)==2)
	{
		bool flag[470]={0};
		for(i=1;i<=F;i++)
		{
			scanf("%d",&a);
			for(j=1;map[a][j]!='\0';j++)
				flag[map[a][j]]=1;
		}
		k=0;
		save=-100000;
		for(i=1;i<=N;i++)
		{
			scanf("%s",str);
			len=strlen(str);
			if(len>=save)
			{
				for(j=0;j<len;j++)
					if(flag[str[j]])
						break;
				if(j==len)
				{
				if(len>save)
				{
					k=0;
					save=len;
					strcpy(res[k++],str);
				}
				else if(len==save)
					strcpy(res[k++],str);
				}
			}
		}
		bool ok[5200]={0};
		j=0;
		if(k)
		{
			qsort(res,k,sizeof(res[0]),cmp);
			j=1;
			ok[0]=1;
		}
		for(i=1;i<k;i++)
		{
			if(strcmp(res[i],res[i-1]))
			{
				j++;
				ok[i]=1;
			}
		}
		printf("%d\n",j);
		for(i=0;i<k;i++)
			if(ok[i])
			  printf("%s\n",res[i]);
	}
	return 0;
}
