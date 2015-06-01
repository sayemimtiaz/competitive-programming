#include<stdio.h>
#include<iostream.h>
#include<string.h>
char word[1000][1000],temp[1000];
int main()
{
	int kase,no_wrd,press,im,in,i,j,k,l1,l2,match,min,h,az;
	cin>>kase;
	//scanf("%d",&kase);
	while(kase--)
	{

		cin>>no_wrd;
		//scanf("%d",&no_wrd);
		for(i=0;i<no_wrd;i++)
			cin>>word[i];
		press=strlen(word[0]);
		for(i=1;i<no_wrd;i++)
		{
			h=1;
			l1=strlen(word[i-1]);
			for(j=i;j<no_wrd;j++)
			{
				l2=strlen(word[j]);
				min=(l1>l2)?l2:l1;
				match=0;
				for(k=0;k<min;k++)
				{
					if(word[i-1][k]==word[j][k])
						match++;
					else
						break;
				}
				if(h)
				{
					h=0;
					im=match;
					in=j;
					az=l2;
				}
				else if(match>im)
				{
					im=match;
					in=j;
					az=l2;
				}
					
			}
			strcpy(temp,word[i]);
			strcpy(word[i],word[in]);
			strcpy(word[in],temp);
			press+=(az-im);
		}
		cout<<press<<endl;
		//printf("%d\n",press);
		for(i=0;i<no_wrd;i++)
		{
			cout<<word[i]<<endl;;
			//printf("%s\n",word[i]);
		}
	}
	return 0;
}