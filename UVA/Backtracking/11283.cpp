
#include<stdio.h>
#include<string.h>
int x[8]={0,0,1,-1,-1,1,-1,1};
int y[8]={-1,1,0,0,-1,1,1,-1};
char grid[10][10];
bool vis[10][10],gflag;
char word[1000];
int len;
void check(long a,long b,long how)
{
  if(how==len)
    {gflag=1;return;}
    int i,c,d;
   for(i=0;i<8;i++)
   {
        c=a+x[i];
        d=b+y[i];
        if(c>=0&&c<4&&d>=0&&d<4&&!vis[c][d]&&grid[c][d]==word[how])
        {
				vis[c][d]=1;
				check(c,d,how+1);
				vis[c][d]=0;
         }
	}
}
int main()
{
	int point[10]={0,0,0,1,1,2,3,5};
	int kase,i,j,kas=1,cnt,m,n,k;
	char str[10000];
	bool flag;
	 gets(word);
    sscanf(word,"%d",&kase);
	while(kase--)
	{ 
		getchar();
		for(i=0;i<4;i++)
		  gets(grid[i]);
        gets(word);
    sscanf(word,"%d",&n);
		cnt=0;
		for(k=0;k<n;k++)
		{
			gets(word);
		     len=strlen(word);
			flag=0;
			for(i=0;i<4&&!flag;i++)
				for(j=0;j<4&&!flag;j++)
				{
					if(word[0]==grid[i][j])
					{
                        gflag=0;vis[i][j]=1;
						check(i,j,1);
						vis[i][j]=0;
						if(gflag)
                           flag=1;
						
					}
				}
			 if(flag)
			 {
			  if(len>7)
			   cnt+=11;
		      else
		      cnt+=point[len];
              }
		}
		printf("Score for Boggle game #%d: %d\n",kas++,cnt);
		
	}
	return 0;
}
