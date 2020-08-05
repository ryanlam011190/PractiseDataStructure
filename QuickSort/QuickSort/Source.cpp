/*For quicksort, we can choose a pivot then move it to the middle
of the array, then all elements of pivot have to be smaller than pivot 
and right elements have to be greater. We dont have to create new arrays
and delete them afterwork. We can work directly on the original array
*/
#include <iostream>
using namespace std;
/*Function Partition is to find the pivot in the array so we can rearrange
the array bases on the pivot. The function will return the pivot
*/
int Partition(int A[], int start, int end)
{
	int pivot = A[end];
	int Pindex = start;
	//run the loop to swap elements 
	for (int i = start; i < end; i++) //except pivot
	{
		if (A[i] <= pivot)
		{
			int temp = A[Pindex];
			A[Pindex] = A[i];
			A[i] = temp;
			Pindex++;
		}
	}
	//until this point, we only need to swap the element at pindex
	//with the pivot (last element)
	int temp1 = A[Pindex];
	A[Pindex] = A[end];
	A[end] = temp1;
	return Pindex;
}
/*After finding and rearrange the pivot, we create a function called quicksort
to sort the array on the left of pivot and the array on the right of pivot
*/
void Quicksort(int A[], int start, int end)
{
	//base case: if there is only 1 element >> exit
	//if there is invalid array >> also exit
	if (start >= end)
		return;
	int Pindex = Partition(A, start, end);
	Quicksort(A, start, Pindex-1);
	Quicksort(A, Pindex + 1, end);
}
int main()
{
	int A[] = {7,6,5,4,3,2,1,0};
	Quicksort(A,0,7);
	for (int i = 0; i < 8; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}