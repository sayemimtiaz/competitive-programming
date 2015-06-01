#include<stdio.h>
#include<math.h>

int main()
{
long unsigned kase,im,s,div,l,u,maxnum,maxdiv,i,j,k;
scanf("%lu",&kase);
while(kase--)
{
scanf("%lu%lu",&l,&u);
maxdiv=0;
for(j=l;j<=u;j++)
{
s=0;
div=0;
for(k=1;k<=sqrt(j);k++)
{
if(j%k==0)
{
div++;
im=j/k;
if(im>k)
div++;
}
}
if(div>maxdiv)
{
maxdiv=div;
maxnum=j;
}
}
printf("Between %lu and %lu, %lu has a maximum of %lu divisors.\n",l,u,maxnum,maxdiv);
}
return 0;
}