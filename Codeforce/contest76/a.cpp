#include<string>
#include<map>
#include<iostream>
using namespace std;
int main()
{
    string str,temp;
    char res[100];
    int i,j,k;
    map<string,char>m;
    cin>>str;
    for(i=0;i<10;i++)
    {
       cin>>temp;
       m[temp]=i+'0';     
    }
    temp[10]='\0';j=0;
    k=0;
    for(i=0;i<=80;i++)
    {
       if(j==10)
       {
         j=0;
         res[k++]=m[temp];
           temp[j++]=str[i];
       }
       else
        temp[j++]=str[i];
    }
    res[k]='\0';
    cout<<res<<endl;
    return 0;
}
