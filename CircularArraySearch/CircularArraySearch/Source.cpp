#include <iostream>
using namespace std;
int  CircularSearch(int A[], int n, int x)
{
	int low = 0; 
	int high = n - 1;
	while (low <= high) //always condition for the loop in BS
	{
		int mid = (low + high) / 2;
		//case 1: if x is mid then done.
		if (A[mid] == x)
			return mid;
		//case 2: if the right haft is sorted
		if (A[mid] <= A[high])
		{
			//case A if x on the right haft then just do BS normally
			if (x > A[mid] && x <= A[high])
				low = mid + 1;
			//case B if x on the left half 
			else
				high = mid - 1; // discard 1 case
		}
		//case 3: if the left half is sorted
		else
		{
			if (x >= A[low] && x < A[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int A[] = {12,14,18,21,3,6,8,9};
	int x;
	cout << "Please enter a number!" << endl;
	cin >> x;
	int index = CircularSearch(A, 8, x);
	if (index == -1)
			cout << "Sorry! we cant find it" << endl;
	else
			cout << "Your number " << x << " is at: " << index;
}