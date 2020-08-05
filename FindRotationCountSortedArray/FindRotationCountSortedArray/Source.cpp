#include <iostream>
using namespace std;
int findRotationCount(int A[], int n)
{
	int low = 0, high = n-1;
	while (low <= high) //its already sorted
	{
		//Case 1: low is at the beginning >> number at
		//low is less than high
		if (A[low] < A[high])
			return low; // low is number of rotation which is 0
		
		//Case2: mid is the pivot
		int mid = (low + high) / 2;
		//if mid is last element % will get it to the first
		int next = (mid + 1) % n;
		int prev = (mid - 1) % n;
		if (A[mid] <= A[next] && A[mid] <= A[prev])
			return mid;
		//case 3: if pivot is on the left of mid
		//the smallest # is on the left of mid
		else if (A[mid] <= A[high])
		{
			high = mid - 1; //cut the array in half
		}
		//case 4: pivot on the right
		else if (A[mid] >= A[high])
			low = mid + 1;
	}
	return -1;
}
int main()
{
	int A[] = {15,22,23,28,5,6,8,10,12};
	int count = findRotationCount(A,10);
	cout << "The array is rotated " << count << endl;
}