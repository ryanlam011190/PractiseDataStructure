#include "Header.h"
#include <iostream>
using namespace std;
int findMin(Node* root)
{
	Node* temp = root;
	temp = temp->left;
	if (root == NULL)
	{
		cout << "Error: Tree is empty" << endl;
		return -1;
	}
	while (temp->left != NULL)
	{
		temp = temp->left; //keep moving
	}
	return temp->data;
	/* recursive manner
	if (root == NULL)
	{
		cout << "Error: " << endl;
		return -1;
	}
	else if (root->left == NULL)
	{
		return root->data;
	}
	return Findmin(root->left);	*/

}
int findMax(Node* root)
{
	if (root == NULL)
	{
		cout << "Error: Tree is empty" << endl;
		return -1;
	}
	while (root->right != NULL)
	{
		root = root->right; // keep moving until 0
	}
	return root->data;
}