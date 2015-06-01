#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef vector<long>vi;
typedef queue<long>qi;
vi adj[5010];
qi q;
char node[5010][110];
bool vis[5010];
long d[5010],nd;
long bin(char *str)
{
     long i;
       for(i=0;i<nd;i++)
        if(!strcmp(str,node[i]))
           return i;
     strcpy(node[nd],str);
     nd++;
     return nd-1;
}
long ser(char *str)
{
     long i;
       for(i=0;i<nd;i++)
        if(!strcmp(str,node[i]))
           return i;
     return -1;
}
void bfs()
{
     long a,b,i;
     while(!q.empty())
     {
        a=q.front();
        q.pop();
         for(i=0;i<adj[a].size();i++)
         {
            b=adj[a][i];
            if(!vis[b])
            {
              d[b]=d[a]+1;
              q.push(b);
              vis[b]=1;
            }
         }
     }
                      
}
int main()
{
    long kase,kas=1,p,n,i,j,k,pos,a[5000],source;
    char c[50000],str[50000];
    scanf("%ld",&kase);
    while(kase--)
    {
      scanf("%ld %ld",&p,&n);
      getchar();
      nd=0;
      source=-1;
      while(p--)
      {
         gets(str);
         j=k=0;
       bool  flag=1;
         for(i=0;str[i]!='\0';i++)
         {
           if(str[i]==' '&&!j)
           {
             flag=1;
             continue;
            }
           if((str[i]==','||str[i]==':')&&str[i-1]=='.')
           {
             if(flag)
             {
              flag=0;
             c[j]='\0';
             pos=bin(c);
             if(!strcmp(c,"Erdos, P."))
               source=pos;
             a[k++]=pos;
             }
             j=0;
               
           }
           else
            c[j++]=str[i];                        
         }
         for(i=0;i<k;i++)
          for(j=i+1;j<k;j++)
          { adj[a[i]].push_back(a[j]);adj[a[j]].push_back(a[i]);}
      }
      printf("Scenario %ld\n",kas++);
      while(n--)
      {
                gets(c);
        if(source!=-1)
        {
        memset(vis,0,sizeof(vis));
        for(i=0;i<nd;i++)
         d[i]=0;
        q.push(source);vis[source]=1;
        j=0;
        pos=ser(c);
        bfs();
        if(pos==-1)
         printf("%s infinity\n",c);
        else if(!strcmp(c,"Erdos, P."))
        printf("%s 0\n",c);
        else if(d[pos])
         printf("%s %ld\n",c,d[pos]);
        else
         printf("%s infinity\n",c);
         }
         else
         printf("%s infinity\n",c);
      }
      for(i=0;i<nd;i++)
       adj[i].clear();               
    }
    return 0;
}
