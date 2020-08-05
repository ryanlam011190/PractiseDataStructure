#include <iostream>
using namespace std;
int BNSRecursion(int A[], int low, int high, int x)
{
	//base cases
	int mid = (low + high) / 2;
	if (A[mid] == x) //base case 1
		return mid;
	if (low >= high) //base case 2
		return -1;
	else if (x < A[mid])
		BNSRecursion(A, 0, mid - 1, x);
	else
		BNSRecursion(A,mid+1,high,x);
}
int main()
{
	int A[] = {2,3,6,9,10,14,54,64,67 };
	int n;
	cout << "Please enter a number to do binary search: " << endl;
	cin >> n;
	int index = BNSRecursion(A, 0, 8, n);
	if (index != -1)
		cout << "Your number " << n << " is at position: "
		<< index << endl;
	else
		cout << "Number is not found! " << endl;
}