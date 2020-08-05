#include <iostream>
using namespace std;
int BinarySearch(int A[], int n, int x, bool searchFirst)
{
	int low = 0; 
	int high = n - 1;
	int result = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (A[mid] == x)
		{
			result = mid; //result now is at n-1
			if (searchFirst)
				high = mid - 1; //keep going to the left
			else
				low = mid + 1; // keep going to the right			
		}
		else if (x < A[mid])
		{
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return result;
}
int main()
{
	int A[] = {1,1,3,3,3,3,3,5,5,5,5,6,6,9,9,11,11 };
	int x;
	cout << "Please enter a number to count" << endl;
	cin >> x;
	int FirstIndex = BinarySearch(A, sizeof(A) / sizeof(A[0]), x, true);
	if (FirstIndex == -1)
		cout << "Sorry! i can find your number in array!!!" << endl;
	else
	{
		int lastIndex = BinarySearch(A, sizeof(A) / sizeof(A[0]), x, false);
		cout << "Count of " << x << " is: " << lastIndex - FirstIndex + 1 << endl;
	}
}