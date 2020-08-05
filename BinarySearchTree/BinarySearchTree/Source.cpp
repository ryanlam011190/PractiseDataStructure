#include <iostream>
#include "Header.h"
using namespace std;
Node* newNode(int data)
{
	//create new node. This function is for
	//the sake of size.
	Node* temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
Node* insert(Node* root, int data)
{
	//a place to insert node
	if (root == NULL)
	{
		root = newNode(data); //create the first node
		return root;
	}
	//if data to be inserted <= data of the current node
	else if (data <= root->data)
	{
		//we need to point root to the left. Remember
		//root is the current node
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;
}
bool search(Node* root, int data)
{
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return search(root->left, data);
	else return search(root->right, data);

}
int main()
{
	//create an empty tree
	Node* root = NULL; //empty tree
	root = insert(root,15); // building link
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 25);
	root = insert(root, 8);
	root = insert(root, 12);
	int number;
	cout << "Please enter a number to be searched " << endl;
	cin >> number;
	if (search(root, number) == true)
		cout << "Found it <3 " << endl;
	else cout << "Sorry! its not found :(";
}