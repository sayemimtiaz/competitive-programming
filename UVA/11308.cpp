#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct price
{
   char name[10000];
   long cost;
}plist[110];
struct recipe
{
  char name[10000];
  long cost;
}rlist[110];
int cmp1(const void *a,const void *b)
{
    price *x=(price*)a;
    price *y=(price*)b;
    return (strcmp(x->name,y->name));
}
int cmp2(const void *a,const void *b)
{
    recipe *x=(recipe*)a;
    recipe *y=(recipe*)b;
    if(x->cost!=y->cost)
      return (x->cost-y->cost);
    else
       return (strcmp(x->name,y->name));
}
int main()
{
    long bb,sum,i,kase,m,n,b,k,s,e,mid,amnt,v;
    char title[20000],str[20000],ch[20000];
    scanf("%ld",&kase);
    while(kase--)
    {
       getchar();
       gets(title);
       for(i=0;title[i]!='\0';i++)
        title[i]=toupper(title[i]);
       scanf("%ld %ld %ld",&m,&n,&b);
       for(i=0;i<m;i++)
        scanf("%s %ld",plist[i].name,&plist[i].cost);   
       qsort(plist,m,sizeof(price),cmp1);
       bb=0;
      while(n--)
      {
        getchar();
        gets(str);
        scanf("%ld",&k);
        sum=0;
        while(k--)
        {
          scanf("%s %ld",ch,&amnt);
          s=0;e=m-1;
          while(s<=e)
          {
            mid=(s+e)/2;
            v=strcmp(ch,plist[mid].name);
            if(!v)
              break;
            else if(v>0)
              s=mid+1;
            else
             e=mid-1;
          }
          sum+=plist[mid].cost*amnt;
        }
        if(sum<=b)
        {
          strcpy(rlist[bb].name,str);
          rlist[bb++].cost=sum;
        }
      }
      qsort(rlist,bb,sizeof(recipe),cmp2);
      printf("%s\n",title);
      if(bb)
      for(i=0;i<bb;i++)
       printf("%s\n",rlist[i].name);
      else
       printf("Too expensive!\n");
      printf("\n");
    }
    return 0;
}
