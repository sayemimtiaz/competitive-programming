#include<stdio.h>
#include<string.h>
#define MAXW 1200
#define MAXL 500
#define UP 1
#define SIDE 2
#define  CROSS 3
void print_lcs(int ,int);
bool flag;
int c[1200][1200],m,n,b[1200][1200];
char s1[MAXW][MAXL],s2[MAXW][MAXL];
void lcs()
{
	int i,j;
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=0;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!strcmp(s1[i-1],s2[j-1]))
			{
				c[i][j]=c[i-1][j-1]+1;
                b[i][j]=CROSS;
            }
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=UP;
            }
			else
			{
                c[i][j]=c[i][j-1];
                b[i][j]=SIDE;
            }
		}
	}
}
void print_lcs(int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==CROSS)
	{
		print_lcs(i-1,j-1);
		if(flag)
		printf(" ");
		else
         flag=1;
		printf("%s",s1[i-1]);
	}
	else if(b[i][j]==UP)
		print_lcs(i-1,j);
	else
		print_lcs(i,j-1);
}
int main()
{
    char str[MAXW],*pch;
	while(gets(str))
	{
       m=0;
       while(str[0]!='#')
       {
         pch=strtok(str," ");
         while(pch!=NULL)
         {
            strcpy(s1[m++],pch);
            pch=strtok(NULL," ");
         }                
         gets(str);
       }
      n=0;
      while(gets(str)&&str[0]!='#')
      {
        pch=strtok(str," ");
         while(pch!=NULL)
         {
            strcpy(s2[n++],pch);
            pch=strtok(NULL," ");
         }
      }
      flag=0;
      lcs();
      print_lcs(m,n);
      printf("\n");
    }
	return 0;
}
