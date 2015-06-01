#include<cstdio>
#include<vector>
using namespace std;
vector<char>v[100009];
char str[200000];
int main()
{
    int i,Top,sz,j;
    bool flag;
    while(gets(str))
    {
      Top=0;flag=1;
      for(i=0;str[i]!='\0';i++)
      {
        if(!flag)
        {
          if(str[i]=='['&&!v[Top].empty())
           Top++;
          else if(str[i]==']')
           flag=1;
          else if(str[i]!='[')
           v[Top].push_back(str[i]);
        }
        else if(str[i]=='[')
        {
          if(!v[Top].empty())
           Top++;
          flag=0;
        }
        else if(str[i]==']')
             flag=1;
        else if(flag)
            v[0].push_back(str[i]);
      }
      for(i=Top;i>=0;i--)
      {
        sz=v[i].size();
        for(j=0;j<sz;j++)
         putchar(v[i][j]);
      }
      printf("\n");
      for(i=Top;i>=0;i--)
        v[i].clear();
    }
    return 0;
}
