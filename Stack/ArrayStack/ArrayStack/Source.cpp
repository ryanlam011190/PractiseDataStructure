#include <iostream>
#define MAX_SIZE 101
using namespace std;
int Array[MAX_SIZE];
//top = -1 means a empty stack so we can use it
//to implement push by doing top = top +1 and
// pop by doing top = top -1;
int top = -1;
void push(int x)
{
	if (top == MAX_SIZE - 1) //last element of the array
	{
		cout << "Error: stack overflow" << endl;
		return;
	}
	top = top + 1;
	Array[top] = x; //first is top[1], then top[2],...
	//or Array[++top] = x >> increment happens before operation
}
void pop()
{
	if (top == -1)
	{
		cout << "Error: No element to pop " << endl;
		return;
	}
	top--;
}
int Top()
{
	return Array[top];
}
void print()
{
	cout << "The stack is: ";
	for (int i = 0; i <= top; i++)
	{
		cout << " " << Array[i];
	}
	cout << endl;
}
int main()
{
	push(2); print();
	push(5); print();
	push(10); print();
	pop(); print();
	push(12); print();
}