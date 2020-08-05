#include <iostream>
#include <array>
#include <vector>
using namespace std;
void selectionsort(int array[], int n)
{
	int temp;
	int IndexMin;
	//we have 2 arrays. Find the minimum of the first
	//array then swap it with the first i.
	for (int i = 0; i < n-1; i++)
	{
		// we start at index 0 minimum 
		IndexMin = i; //indexmin is now 0
		//find minimum in the 2nd array
		for (int j = i+1; j < n; j++)
			if (array[j] < array[IndexMin])
			{
				IndexMin = j;
			}
		temp = array[i];
		array[i] = array[IndexMin];
		array[IndexMin] = temp;;
	}
}
int main()
{
	int array[20] = {10,8,9,5,6,3 };
	selectionsort(array,6);
	for (int i = 0; i < 6; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}