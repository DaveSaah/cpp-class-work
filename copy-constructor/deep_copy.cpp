#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char *s2;
	char *s1;
	
	s2 = new char[5];
	strcpy(s2, "kofi");
	
	s1 = new char[5];
	strcpy(s1,s2);
	
	cout << s1 << endl;
	delete s1;
	cout << s2 << endl;
	
	return 0;
}
