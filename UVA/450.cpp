#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct T
{
	char title[800],first[800],dept[800],last[800],street[800],home[800],work[800],campus[800];
}person[50000];
char str[1005000],ch[1005000],dpt[1005000];
int cmp(const void *a,const void *b)
{
   T *p=(T *)a;
   T *q=(T *)b;
   return strcmp( p->last,q->last );
}
int main()
{
	long n,i,j,k,m=0;
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
	  gets(dpt);
	  while(gets(str))
	  {
		  if(str[0]=='\0')
			  break;
		 strcpy(person[m].dept,dpt);
		  k=j=0;
	  for(i=0;str[i]!='\0';i++)
	  {
		  if(str[i]==',')
		  {
			  ch[j]='\0';
			  if(k==0)
			  {
				  k=1;
				  strcpy(person[m].title,ch);
			  }
			  else if(k==1)
			  {
				   k=2;
				  strcpy(person[m].first,ch);
			  }
			  else if(k==2)
			  {
				   k=3;
				  strcpy(person[m].last,ch);
			  }
			  else if(k==3)
			  {
				   k=4;
				  strcpy(person[m].street,ch);
			  }
			  else if(k==4)
			  {
				   k=5;
				  strcpy(person[m].home,ch);
			  }
			   else
				  strcpy(person[m].work,ch);
			   j=0;

		  }
		  else
			  ch[j++]=str[i];
	  }
	  ch[j]='\0';
	  strcpy(person[m++].campus,ch);
	  }
	}
	qsort(person,m,sizeof(T),cmp);
	for(i=0;i<m;i++)
	{
		printf("----------------------------------------\n");
		printf("%s %s %s\n",person[i].title,person[i].first,person[i].last);
		printf("%s\n",person[i].street);
		printf("Department: %s\n",person[i].dept);
		printf("Home Phone: %s\n",person[i].home);
		printf("Work Phone: %s\n",person[i].work);
		printf("Campus Box: %s\n",person[i].campus);
	}
	return 0;
}