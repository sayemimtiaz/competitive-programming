#include<stdio.h>
#include<string.h>
char R[1213][5000];
void add(int n1,int n2,int nn)
{
	char tmp[5000],res[5000],s1[5000],s2[5000];
	int l1,l2,i,temp,m,n,sum,hold,j;
	strcpy(s1,R[n1]);
	strcpy(s2,R[n2]);
	l1=strlen(s1);
	l2=strlen(s2);
	if(l2>l1)
	{
		temp=l1;
		l1=l2;
		l2=temp;
		strcpy(tmp,s1);
		strcpy(s1,s2);
		strcpy(s2,tmp);
	}
	m=l1-1;
	n=l2-1;
	for(i=0,hold=0;i<l1;i++)
	{
		if(n>=0)
		sum=(s1[m--]-'0')+(s2[n--]-'0')+hold;
		else
		sum=(s1[m--]-'0')+hold;
		res[i]=sum%10+'0';
		hold=sum/10;
	}
	if(hold)
		res[i++]=hold+'0';
	for(j=i-1;j>=0;j--)
		R[nn][i-1-j]=res[j];
	R[nn][i]='\0';

}
int main()
{
    int i;
    strcpy(R[1],"2");
    strcpy(R[2],"5");
    strcpy(R[3],"13");
    for(i=4;i<=1000;i++)
    {
       add(i-3,i-2,i);add(i,i-1,i);add(i,i-1,i);
    }
    while(~scanf("%d",&i))
     printf("%s\n",R[i]);
    return 0;
}
