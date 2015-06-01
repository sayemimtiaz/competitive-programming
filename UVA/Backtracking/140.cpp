#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
vector<long>adj[550];
bool vis[1000];
char cstr[1000],fstr[1000];
long node[1000],N,save,pos[1000];
void check(long how,long in)
{
long maxi,i,j,p1,p2;
   if(how==N)
   {
     maxi=-1;
     for(i=0;i<N;i++)
     {
       p1=pos[node[i]];
       for(j=0;j<adj[node[i]].size();j++)
        {
          p2=pos[adj[node[i]][j]];
          if(abs(p2-p1)>maxi)
           maxi=abs(p2-p1);
          if(maxi>=save)
           return;
          }
        }
        save=maxi;
        strcpy(fstr,cstr);
        return;
   }
   for(i=0;i<N;i++)
    if(!vis[i])
    {
      vis[i]=1;
      cstr[in]=(char)node[i];
      cstr[in+1]=' ';
      pos[node[i]]=how;
      check(how+1,in+2);
      vis[i]=0;
    }  
}
int main()
{
    char ch,str[1000];
    long j,i;
    while(gets(str))
    {
       N=0;
       bool flag[250]={0};
       for(i=0;str[i]!='\0'&&str[i]!='#';i++)
       {
          if(str[i]==':')
          {
             ch=str[i-1];
             if(!flag[ch])
             {flag[ch]=1;node[N++]=str[i-1];}
             i++;
             while(str[i]!=';'&&str[i]!='\0')
              {
              adj[ch].push_back(str[i]);
              if(!flag[str[i]])
             {flag[str[i]]=1;node[N++]=str[i];}
              i++;}
             i--;
          }
       }
       if(str[i]=='#')
        break;
        sort(node,node+N);
        cstr[2*N-1]='\0';
       save=2147483647;
       check(0,0);
       printf("%s-> %ld\n",fstr,save);
       for(i=0;i<N;i++)
        adj[node[i]].clear();
    }
    return 0;
}
