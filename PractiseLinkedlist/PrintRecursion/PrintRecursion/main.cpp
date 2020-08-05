#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* insert(Node* head, int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		Node* temp1 = head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp->next;
		temp1->next = temp;
	}
	return head;
}
//print linkedlist using recursive
void print(Node* p)
{
	if (p == NULL)
		return;
	print(p->next);
	cout << " " << p->data;
}
/*void print(Node* p)
{
	if (p == NULL)
		return;
	cout << " " << p->data;
	print(p->next);
}*/
int main()
{
	Node* head = NULL;
	head = insert(head, 2);
	head = insert(head, 4);
	head = insert(head, 6);
	head = insert(head, 5);
	print(head);
}
