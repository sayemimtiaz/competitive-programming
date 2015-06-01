#include<iostream.h>
#include<string.h>
char a[4]={'2','4','6','8'};
char b[10][10][100];

int main()
{
	int i=0;
	strcpy(b[0][0],"00");strcpy(b[0][1],"01");strcpy(b[0][2],"81");strcpy(b[0][3],"");
strcpy(b[1][0],"0000");strcpy(b[1][1],"0001");strcpy(b[1][2],"2025");
strcpy(b[1][3],"3025");strcpy(b[1][4],"9801");strcpy(b[1][5],"");
strcpy(b[2][0],"000000");strcpy(b[2][1],"000001");strcpy(b[2][2],"088209");
strcpy(b[2][3],"494209");strcpy(b[2][4],"998001");strcpy(b[2][5],"");
strcpy(b[3][0],"00000000");strcpy(b[3][1],"00000001");strcpy(b[3][2],"04941729");
strcpy(b[3][3],"07441984");strcpy(b[3][4],"24502500");strcpy(b[3][5],"25502500");
strcpy(b[3][6],"52881984");strcpy(b[3][7],"60481729");strcpy(b[3][8],"99980001");
strcpy(b[3][9],"");
	char ch;
	while(cin>>ch)
	{
		for(i=0;i<4;i++)
			if(ch==a[i])
				break;
			int j=0;
		while(strcmp(b[i][j],""))
		{
			cout<<b[i][j]<<endl;
			j++;
		}
	}
	return 0;
}

