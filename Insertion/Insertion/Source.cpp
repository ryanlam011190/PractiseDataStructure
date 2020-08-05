#include <iostream>
using namespace std;
void insertion(int array[], int n)
{
	int CurrentValue;
	int hole;
	int temp;
	for (int i = 1; i < n; i++)
	{
		CurrentValue = array[i]; //create a hole
		hole = i; //hole holds the postion
		while (hole > 0 && array[hole - 1] > CurrentValue)
		{
			array[hole] = array[hole-1];
			hole--;
		}
		array[hole] = CurrentValue;
	}
}
int main()
{
	int array[20] = {2,6,3,4,1,7};
	insertion(array, 6);
	cout << "Your array after using InsertionSort is: " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}