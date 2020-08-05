#include <iostream>
#include "Header.h"
using namespace std;
bool IsSubTreeLesser(Node* root, int value)
{
	if (root == NULL)
		return true;
	if (root->data <= value && IsSubTreeLesser(root->left, value)
		&& IsSubTreeLesser(root->right, value))
		return true;
	else
		return false;
}
bool IsSubTreeGreater(Node* root, int value)
{
	if (root == NULL)
		return true;
	if (root->data > value&& IsSubTreeGreater(root->left, value)
		&& IsSubTreeGreater(root->right, value))
		return true;
	else
		return false;
}
bool IsBST(Node* root)
{
	if (root == NULL)
		return true;
	//go to left all the time
	//return true if all elements left subtree are lesser
	//and all right are greater
	if (IsSubTreeLesser(root->left, root->data) &&
		IsSubTreeGreater(root->right, root->data) &&
		IsBST(root->left) && IsBST(root->right))
	{
		return true;
	}
	else
		return false;
}
//better solution
bool isBST(Node* root, int min, int max)
{
	if (root == NULL)
		return true;
	if (root->data > min&& root->data < max
		&& isBST(root->left, min, root->data)
		&& isBST(root->right, root->data, max))
		return true;
	else
		return false;
}