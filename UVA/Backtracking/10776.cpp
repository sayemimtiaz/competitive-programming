#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char O[1000],a[1000];
int L,H;
void recur(int how,int s)
{
     if(how==H)
     {
       printf("%s\n",a);
       return;
     }
     int i,rp=-1;
     for(i=s;i<L;i++)
     {
        if(rp!=(int)O[i])
        {
        rp=(int)O[i];
        a[how]=O[i];
        recur(how+1,i+1);
        }
     }
}
int main()
{
    char str[1000];
    while(gets(str))
    {
      sscanf(str,"%s %d",O,&H);
      L=strlen(O);
      sort(O,O+L);
      a[H]='\0';
      recur(0,0);
    }
    return 0;
}
