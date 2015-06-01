#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
char line[10001];
int r,i,j,k,len,kase;
double sqr,rt;
while(scanf("%d\n",&kase)==1)
{
for(k=1;k<=kase;k++)
{
gets(line);
len=strlen(line);
rt=(int)(sqrt(len));
sqr=(rt*rt);
if(len!=sqr) printf("INVALID\n");
else
{
int t=0;
r=((int)sqrt(len));
for(i=0;i<r;i++)
{
for(j=i;j<len;j+=r)
{
printf("%c",line[j]);
}
}
printf("\n");
}
}

}
return 0;
}