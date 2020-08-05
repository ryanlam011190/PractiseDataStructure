#include<iostream>
using namespace std;
void BubbleSort(int array[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
int main()
{
	int Array[20] = {2,3,1,8,4,5,9};
	BubbleSort(Array, 6);
	cout << "Your array after using bubblesort is: " << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}