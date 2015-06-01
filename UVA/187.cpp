#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
typedef vector<long>vi;
vi sqac[1000000];
vi sqam[1000000];
char account[10000][100];
long store[100000],fluc[10000];
int main()
{
	long i,j,save,index,k;
	bool flag;
	char str[60000],ch[60000],chh[60000];
	while(gets(str)&&(str[0]!='0'||str[1]!='0'||str[2]!='0'))
	{
		ch[0]=str[0];ch[1]=str[1];ch[2]=str[2];ch[3]='\0';
		strcpy(account[atol(ch)],&str[3]);
	}
	memset(fluc,0,sizeof(fluc));
	flag=1;
	k=0;
	while(gets(str)&&(str[0]!='0'||str[1]!='0'||str[2]!='0'))
	{
		ch[0]=str[0];ch[1]=str[1];ch[2]=str[2];ch[3]='\0';
		chh[0]=str[3];chh[1]=str[4];chh[2]=str[5];chh[3]='\0';
		index=atol(ch);
		sqac[index].push_back(atol(chh));
		strcpy(str,&str[6]);
		sqam[index].push_back(atol(str));
		fluc[index]+=atol(str);
		if(flag)
		{
			flag=0;
			save=index;
		}
		else if(save!=index)
		{
			if(fluc[save])
				store[k++]=save;
			save=index;
		}

	}
	if(fluc[save])
		store[k++]=save;
	for(i=0;i<k;i++)
	{
		printf("*** Transaction %ld is out of balance ***\n",store[i]);
		for(j=0;j<sqac[store[i]].size();j++)
		{
			printf("%ld %-31s %9.2lf\n",sqac[store[i]][j],account[sqac[store[i]][j]],sqam[store[i]][j]/(double)100);
		}
		printf("999 %-31s %9.2lf\n\n","Out of Balance",(fluc[store[i]]>0)?(fluc[store[i]]/(double)100):-(fluc[store[i]]/(double)100));
	}
	return 0;
}