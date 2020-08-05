#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head;
Node* reverse(Node* head)
{
	Node* current = head; //point to HEAD and will move to the end
	Node* previous = NULL; // POINT TO NOTHING and will move after current
	Node* next = NULL; // to keep the address the next Node
	while (current != NULL)
	{
		next = current -> next; //store the address of the node after current
		current->next = previous; //go backward
		previous = current;
		current = next;
	}
	//previous will store the address of the last node
	//we have to adjust the head now
	head = previous;
	return head;
}
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
			temp->next = temp1->next;
		}
		temp1->next = temp;
	}
	return head;
}
void print(Node* head)
{
	while (head != NULL)
	{
		cout << " " << head->data;
		head = head->next;
	}
}
int main()
{
	Node* head = NULL;
	head = insert(head,2);
	head = insert(head,4);
	head = insert(head,6);
	head = insert(head,8);
	print(head);
	cout << endl;
	head = reverse(head);
	print(head);
}
