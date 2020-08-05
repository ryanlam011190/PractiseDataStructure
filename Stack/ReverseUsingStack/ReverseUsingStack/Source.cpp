#include <iostream>
#include <stack> //sttandard template library
#include "Header.h"
using namespace std;
void reverse(char *c, int n)
{
	stack <char> S; //create vector of character
	for (int i = 0; i < n; i++)
	{
		S.push(c[i]);//push every single character to stack
	}
	//after pushing all characters then pop it
	for (int i = 0; i < n; i++)
	{
		c[i] = S.top(); //get top
		S.pop(); //perform pop
	}

}
int main()
{
	char a[51];
	cout << "Please input a string ";
	cin >> a;
	reverse(a, strlen(a));
	cout << "Output is: " << a;
}