#include <iostream>
#include "Header.h"
#include <math.h>
Node* Delete(Node* root, int data)
{
	if (root == NULL)
		return root;
	//base case to run around the tree to find
	//the node to delete
	else if (root->data > data)
	{
		root->left = Delete(root->left, data); //to hold the changing adrress
	}
	else if (root->data < data)
		root->right = Delete(root->right, data);
	else
	{
		//Case 1: No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root == NULL;
			return root;
		}
		else if (root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		//case3: 2 children
		else
		{
			Node* temp = FindMin(root->right);
			root->data = temp->data; //copy value to current node
			root->right = Delete(root->right,temp->data)
		}
	}
}