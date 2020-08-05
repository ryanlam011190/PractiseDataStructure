/*when talking about deleting in linkedlist, we have
to remember to use delete function after disconnecting
the link of linkedlist*/
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head;
void insert(int data); //insert integer at end of list
void print()
{

}
void deleteNode(int position) //delete node at position
{
	Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next;
		delete temp1;
		return;
	}
	for (int i = 0; i < position - 2; i++)
	{
		temp1 = temp1->next; //find the node to delete
	}
	Node* temp2 = temp1->next; //point to the node to be deleted
	temp1->next = temp2->next;//temp1 points to temp2
	delete temp2;
}
int main()
{
	head = NULL;
	insert(2);
	insert(4);
	insert(6);
	insert(5); //list 2 4 6 5
	int position;
	cout << " " << position;
	deleteNode(position);
	print();
}