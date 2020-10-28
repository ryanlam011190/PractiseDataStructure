#include <iostream>
using namespace std;
int  CircularSearch(int array[], int n, int x) 
	             < < < < < < < < < < < < < < <  |
   		     |				    |
	// Index:    | 	0    1	 2   3  4  5  6  7  |
	//	     |	11, 13, 14, 18, 3, 5, 6, 8  |
		     |		     |  |	    |
		     | > > > > > > > >	> > > > > > >
{
	//Perform binary search on a sorted and rotated array
	//3 is the start and 18 is the end in this circular array
	int low = 0; 
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		//case 1: if x is mid then done just as any regular case.
		if (array[mid] == x)
			return mid;
		
		//case 2: right half list : 18, 3, 5, 6, 8 (including 18)		
		if (array[mid] <= array[high])
		{
			//case A if x on the right haft then just do BS normally
			//array[mid] < x < array[high]
 			if (x > array[mid] && x <= array[high])
				low = mid + 1;
			//case B if x on the left half 
			else
				high = mid - 1; // discard 1 case
		}
		//case 3: if the left half is sorted
		// 11, 13, 14, 18. In this case, left half is sorted.
		else
		{
			if (x >= array[low] && x < array[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int array[] = {11,13,14,18,3,5,6,8};
	int x;
	cout << "Please enter a number!" << endl;
	cin >> x;
	int position = CircularSearch(array, 8, x);
	if (position == -1)
			cout << "Sorry! your number is in someone else's list, not this list!!!" << endl;
	else
			cout << "Your number " << x << " is at: " << position;
}
