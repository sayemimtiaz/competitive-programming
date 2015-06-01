#include<stdio.h>
#include<string.h>
#include<math.h>

/****Function HeaderFile****/
bool input();
void init();
bool check(int,int);
bool checkMini(int,int,bool);
bool checkRow(int,int,bool);
bool checkCol(int,int,bool);
bool call();
int hold(int,int);
void push_a(int);
void push_b(int);
int pop_a();
int pop_b();
void output();
void reinit(int,int);

/****Global Variable****/
bool cell[10][10][10],glo;
int grid[10][10],size;
int s1[1000000],s2[1000000],t1,t2;

/****Main Function****/
int main()
{
	bool flag=0;
	while(scanf("%d",&size)==1)
	{
	size=size*size;
		init();
	if(input())
	{
	if(call())
	output();
	}
	}
	return 0;
}
void output()
{
	int i,j;
	for(i=0;i<size;i++)
	{
		bool flag=0;
		for(j=0;j<size;j++)
		{
			if(flag)
				printf(" ");
			flag=1;
			printf("%d",grid[i][j]);
		}
		printf("\n");
	}
}
bool input()
{
	bool flag;
	int i,j;
    for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			scanf("%d",&grid[i][j]);
	if(glo)
		printf("\n");
	glo=1;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
		{
			if(grid[i][j])
			{
				flag=checkMini(i,j,0);
				if(flag)
				{
						printf("NO SOLUTION\n");
						return 0;
				}
				flag=checkRow(i,j,0);
				if(flag)
				{
						printf("NO SOLUTION\n");
						return 0;
				}
				flag=checkCol(i,j,0);
				if(flag)
				{
						printf("NO SOLUTION\n");
						return 0;
				}
			}
		}
		return 1;
}
void init()
{
	memset(cell,0,sizeof(cell));
	t1=t2=0;
	push_a(-1);
	push_b(-1);
}
bool call()
{
	int i=0,j=0;
	bool flag;
	while(i<size)
	{
	flag=check(i,j);
	if(flag)
	{
    	j++;
	    if(j>=size)
		{
		  i++;
		  j=0;
		}
	}
	else
	{
		i=pop_a();
	    j=pop_b();
		if(i==-1)
		{
			printf("NO SOLUTION\n");
			return 0;
		}
		grid[i][j]=0;
	}
	}
	return 1;
		
}
bool check(int i,int j)
{
	int a;
	if(!grid[i][j])
	{
		 checkMini(i,j,1);
		 checkRow(i,j,1);
	     checkCol(i,j,1);
		 a=hold(i,j);
		 if(a!=0)
		 {
		 grid[i][j]=a;
	     push_a(i);
	     push_b(j);
		 }
	    else
		{
		    reinit(i,j);
	    	return 0;
		}
	}
	return 1;

}
void reinit(int a,int b)
{
	int i;
	grid[a][b]=0;
	for(i=0;i<size;i++)
		cell[a][b][i]=0;
}
bool checkMini(int a,int b,bool pot)
{
	int c,d;
	int s=sqrt(size);
	if(b<s)
	{
		if(a<s)
		{
			c=0;d=0;
		}
		else if(a<2*s)
		{
			c=s;d=0;
		}
		else
		{
			c=2*s;d=0;
		}
	}
	else if(b<2*s)
	{
		if(a<s)
		{
			c=0;d=s;
		}
		else if(a<2*s)
		{
			c=s;d=s;
		}
		else
		{
			c=2*s;d=s;
		}
	}
	else
	{
		if(a<s)
		{
			c=0;d=2*s;
		}
		else if(a<2*s)
		{
			c=s;d=2*s;
		}
		else
		{
			c=2*s;d=2*s;
		}
	}
	int i,j;
	if(pot)
	{
	for(i=c;i<c+s;i++)
		for(j=d;j<d+s;j++)
		{
			if(grid[i][j])
			{
				cell[a][b][grid[i][j]-1]=1;
			}
		}
	}
	else
	{
			for(i=c;i<c+s;i++)
		for(j=d;j<d+s;j++)
		{
			if((i!=a||j!=b)&&grid[i][j]&&grid[i][j]==grid[a][b])
			{
				return 1;
			}
		}
		return 0;
	}
	return 1;
}
bool checkRow(int a,int b,bool pot)
{
	int i;
	if(pot)
	{
	for(i=0;i<size;i++)
		if(grid[a][i])
		{
			cell[a][b][grid[a][i]-1]=1;
		}
	}
	else
	{
				for(i=0;i<size;i++)
		{
			if((i!=b)&&grid[a][i]&&grid[a][i]==grid[a][b])
			{
				return 1;
			}
		}
		return 0;
	}
	return 1;

}
bool checkCol(int a,int b,bool pot)
{
	int i;
	if(pot)
	{
	for(i=0;i<size;i++)
		if(grid[i][b])
		{
			cell[a][b][grid[i][b]-1]=1;
		}
	}
	else
	{
					for(i=0;i<size;i++)
		{
			if((i!=a)&&grid[i][b]&&grid[i][b]==grid[a][b])
			{
				return 1;
			}
		}
		return 0;
	}
	return 1;

}
int hold(int a,int b)
{
	int i;
	for(i=0;i<size;i++)
		if(!cell[a][b][i])
		{
			cell[a][b][i]=1;
			return i+1;
		}
	return 0;
}
void push_a(int d)
{
	s1[t1++]=d;
}
void push_b(int d)
{
	s2[t2++]=d;
}
int pop_a()
{
	t1--;
	return s1[t1];
}
int pop_b()
{
	t2--;
	return s2[t2];
}

