#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long x[]={0,0,-1,1,-1,1,-1,1};
long y[]={-1,1,0,0,-1,1,1,-1};
bool ctst[200]={0};
bool vis[5][5],got;
char grid[5][5],a[5];
long save,por;
char store[100000][5],st[100000][5];
int cmp(const void *a,const void *b)
{
	return (strcmp((char*)a,(char*)b));
}
bool binser(char *str)
{
	long s=0,e,m;
		e=por-1;
	while(s<=e)
	{
		m=(s+e)/2;
		if(!strcmp(str,st[m]))
			return true;
		if(strcmp(str,st[m])>0)
			s=m+1;
		else
			e=m-1;

	}
	return false;
}
void check(long i,long j,long how)
{
	long k;
	if(how==4)
	{
		long cnt=0;
		for(k=0;k<4;k++)
		{
			if(ctst[a[k]])
				cnt++;
		}
		a[4]='\0';
		if(cnt==2)
		{
			if(got)
			{
				strcpy(st[por++],a);
			}
			else if(binser(a))
				strcpy(store[save++],a);
		}
		return;
	}
	long c,d;
	for(k=0;k<8;k++)
	{
		c=i+x[k];
		d=j+y[k];
		if(c>=0&&d>=0&&c<4&&d<4&&!vis[c][d])
		{
			vis[c][d]=1;
			a[how]=grid[c][d];
			check(c,d,how+1);
			vis[c][d]=0;
		}
	}
}
int main()
{
	ctst['A']=ctst['E']=ctst['I']=ctst['O']=ctst['Y']=ctst['U']=1;
	char b1[5][5],b2[5][5],str[50000];
	long i,j,k;
	bool flag,fl=0;
	while(gets(str)&&strcmp(str,"#"))
	{
		i=0;
		while(1)
		{
			flag=0;
			j=0;
			for(k=0;str[k]!='\0';k++)
			{
				if(str[k]==' ')
					continue;
				if(j==4)
				{
					j=0;
					flag=1;
				}
				if(flag)
					b2[i][j++]=str[k];
				else
				{
					grid[i][j]=str[k];
				   b1[i][j++]=str[k];
				}
			}
			i++;
			if(i==4)
				break;
			gets(str);
		}
		memset(vis,0,sizeof(vis));
		got=1;
		por=save=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				vis[i][j]=1;
				a[0]=grid[i][j];
		        check(i,j,1);
				vis[i][j]=0;
			}
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				grid[i][j]=b2[i][j];
		memset(vis,0,sizeof(vis));
		qsort(st,por,sizeof(st[0]),cmp);
		got=0;
			for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				vis[i][j]=1;
				a[0]=grid[i][j];
		        check(i,j,1);
				vis[i][j]=0;
			}
		qsort(store,save,sizeof(store[0]),cmp);
		if(fl)
			printf("\n");
		fl=1;
		if(!save)
			printf("There are no common words for this pair of boggle boards.\n");
		else
		{
		for(i=0;i<save;i++)
		{
			if(!i||(i&&strcmp(store[i],store[i-1])))
			   printf("%s\n",store[i]);
		}
		}
		gets(str);
	}
	return 0;
}