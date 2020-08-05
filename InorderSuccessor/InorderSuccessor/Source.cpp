#include "Header.h"
#include <iostream>
Node* Getsuccessor(Node* root, int data)
{
	//search the Node - O(h)
	Node* current = Find(root, data);
	if (current == NULL)
		return NULL;
	//Case1: Node has right subtree and find the minimum
	//on the right subtree(means the most left)
	if (current->right != NULL)
	{
		Node* temp = current->right; //temp is going to right
		while (temp->left != NULL)
			temp = temp->left; //traverse to the most left of right subtree
		return temp; //now temp is the successor
	}
	//Case2: no right subtree. If its the node on the left
	// of parent >> the successor is parent
	else
	{
		Node* successor = NULL;
		Node* ancestor = root;
		while (ancestor != current)
		{
			if (current->data < ancestor->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}
