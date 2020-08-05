#include <iostream>
using namespace std;
int Binarysearch(int A[], int n, int x)
{
	int low = 0;
	int high = n - 1;
	while (low <= high) //if its equal we exit
	{
		int midIndex = (high + low) / 2;
		if (x == A[midIndex])
			return midIndex;
		else if (x < A[midIndex])
		{
			high = midIndex - 1; //relocate high index
		}
		else
			low = midIndex + 1;
	}
	return -1;
}
int main()
{
	int A[20] = { 1,4,6,7,10,15,30,39 };
	int n;
	cout << "Please enter a number: " << endl;
	cin >> n;
	int index = Binarysearch(A,8,n);
	if (index != -1)
	{
		cout << "Number " << n << " is at index: " << index << endl;
	}
	else
		cout << "Number " << n << " is not found!" << endl;
} 