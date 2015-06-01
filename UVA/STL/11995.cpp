#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
priority_queue<int>pq;
queue<int>q;
stack<int>s;
int main()
{
    long n,todo,done,take,i;
    bool ss,pp,qq;
    while(scanf("%ld",&n)==1)
    {
       ss=pp=qq=1;
       for(i=1;i<=n;i++)
       {
           scanf("%ld %ld",&todo,&done);
           if(todo==1)
           {
             s.push(done);
             q.push(done);
             pq.push(done);
           }
           else
           {
               if(s.empty()||q.empty()||pq.empty())
               {ss=0;pp=0;qq=0;}
               if(ss)
               {
                 take=s.top();s.pop();
                 if(done!=take)
                   ss=0;
               }
               if(pp)
               {
                 take=pq.top();pq.pop();
                 if(done!=take)
                   pp=0;
               }
               if(qq)
               {
                 take=q.front();q.pop();
                 if(done!=take)
                   qq=0;
               }
           }
       }
       if(!ss&&!pp&&!qq)
         printf("impossible\n");
       else if((ss&&pp)||(ss&&qq)||(pp&&qq))
        printf("not sure\n");
       else if(ss)
        printf("stack\n");
       else if(qq)
        printf("queue\n");
       else
        printf("priority queue\n");
        while(!s.empty())
          s.pop();
        while(!pq.empty())
         pq.pop();
        while(!q.empty())
         q.pop();
    }
    return 0;
}
