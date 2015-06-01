#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
using namespace std;
int main()
{
    int i,j,d;
    char ch,str[500],pr;
    bool flag;
    while(ch=getchar())
    {
       int F[38]={0};
       j=0;pr='1';flag=0;
       while(1)
       {
          if(ch=='#'){
              for(i=1;i<=35;i++)
        if(F[i])
         cout<<i<<" "<<F[i]<<endl;
        cout<<endl;
           break;
           }
           if(ch==' '||ch=='?'||ch==','||ch=='!'||ch=='.')
           {
             F[j]++;
             j=0;
           }
           else if(ch!='\''&&ch!='-'&&ch!='\n')
            j++;
         if(ch=='\n'&&pr!='-') F[j]++,j=0;
         pr=ch;
         ch=getchar();
         if(ch==EOF)
         {flag=1;
          break;}
       }
       if(flag)
        break;
    
        
    }
    return 0;
}
