#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head;
void print(Node* p)
{
	if (p == NULL)
		return;
	print(p->next); //head recursion
	cout << " " << p->data;
}
void reverse(Node* p)
{
	//base case, exit condition
	if (p->next == NULL)
	{
		//traverse till the end of the list then
		//move the head to the back
		head = p; 
		return;
	}
	reverse(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}