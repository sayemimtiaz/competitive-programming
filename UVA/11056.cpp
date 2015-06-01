#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;
struct SS
{
 char name[30];
 long cost;
}S[120];
int cmp(const void *a,const void *b)
{
     SS *x=(SS*)a;
     SS *y=(SS*)b;
     if(x->cost!=y->cost)
      return (x->cost-y->cost);
     long i;
     char t1[1000],t2[1000];
     for(i=0;x->name[i]!='\0';i++)
      t1[i]=tolower(x->name[i]);
     t1[i]='\0';
     for(i=0;y->name[i]!='\0';i++)
      t2[i]=tolower(y->name[i]);
     t2[i]='\0';
     return (strcmp(t1,t2));
}
int main()
{
    long n,min,sec,msec,i,j;
    while(~scanf("%ld",&n))
    {
      for(i=0;i<n;i++)
      {
        scanf("%s %*s %ld %*s %ld %*s %ld %*s",S[i].name,&min,&sec,&msec);
        S[i].cost=(min*60*1000)+(sec*1000)+msec;
      }
      j=0;
      qsort(S,n,sizeof(SS),cmp);
      for(i=0;i<n;i+=2)
      {
        printf("Row %ld\n",++j);
        printf("%s\n",S[i].name);
        if((i+1)<n)
         printf("%s\n",S[i+1].name);
      }
      printf("\n");
    }
    return 0;
}
