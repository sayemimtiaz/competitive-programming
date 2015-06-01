#include <iostream>
#include <algorithm>
using namespace std;

int main () 
{
	long len,kas;
	char str[1000];
	cin>>kas;
	while(kas--)
	{
  cin>>str;
  len=strlen(str);
  sort (str,str+len);

  do 
  {
    cout << str << endl;
  } while (next_permutation(str,str+len) );
  cout<<endl;
	}
  return 0;
}