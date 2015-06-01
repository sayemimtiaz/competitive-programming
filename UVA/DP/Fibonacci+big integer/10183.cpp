#include<string.h>
#include<stdio.h>
char R[4000][120];
int H,mid,L[4000];
int binser(char *a,char *b)
{
    int i,cnt=0,la,lb;
    la=strlen(a);
    lb=strlen(b);
    for(i=1;i<H;i++)
    {
      if(L[i]<la||L[i]>lb)
       continue;
       //printf("%s\n",R[i]);
      if((L[i]>la&&L[i]<lb)||(L[i]==la&&L[i]<lb&&strcmp(R[i],a)>=0)||(L[i]==lb&&L[i]>la&&strcmp(R[i],b)<=0)||(L[i]==lb&&L[i]==lb&&strcmp(R[i],a)>=0&&strcmp(R[i],b)<=0))
       {cnt++;}
    }
    printf("%d\n",cnt);
}
void fibo()
{
	char a[10000]={"1"},b[10000]={"2"},c[10000],t[10000],max_s[10000],min_s[10000];
	int l1,l2, j,k,m,sum,hold;
	strcpy(R[1],a);
	strcpy(R[2],b);
	L[1]=L[2]=1;
	l1=l2=1;
	for(H=3;;H++)
	{
		k=l1-1;
		m=0;
		hold=0;
		for(j=l2-1;j>=0;j--)
		{
			if(k<0)
			sum=(b[j]-'0')+hold;
			else
			{
				sum=(b[j]-'0')+(a[k]-'0')+hold;
				k--;
			}
			t[m]=sum%10+'0';
			hold=sum/10;
			m++;
		}
		if(hold!=0)
		{
		  t[m]=hold+'0';
		  m++;
		}
		t[m]='\0';
		if(m>110)
		 break;
		k=m-1;
		for(j=0;j<m;j++)
		{
			c[j]=t[k];
			k--;
		}
		c[j]='\0';
		strcpy(a,b);
		strcpy(b,c);
		l1=l2;
		l2=m;
		strcpy(R[H],c);
		L[H]=m;
	}
	
}
int main()
{
	int n,res,loc1,loc2,id1,id2;
	char a[1000],b[1000];
	fibo();
	while(scanf("%s %s",a,b)&&(a[0]!='0'||b[0]!='0'))
	{
		binser(a,b);
       
	}
	return 0;
}
