#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char M[1000],str[1000];
    int kase,L,i,kas=1,j;
    unsigned long long temp,res; 
    M['A']=1;M['C']=2;M['G']=3;M['T']=4;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%s",str);
      L=strlen(str);
      res=0;
      for(i=0;i<L;i++)
      {
         temp=1;
         for(j=1;j<L-i;j++)
           temp*=4;
         res+=((M[str[i]]-1)*temp);
      }
      printf("Case %d: (%d:%llu)\n",kas++,L,res);
    }
    return 0;
}
