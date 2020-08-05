#include <iostream>
using namespace std;
/*We need 2 function to do the sort,
one function will split the array into half until the last element
then call the second function to sort it back to 1 array
*/

//this array will merge all the sub arrays back into 1 array
void merge(int A[], int left[],int nleft, int right[], int nright)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < nleft && j < nright)
	{
		//now we compare every single element in each array
		if (left[j] <= right[k])
		{
			A[i] = left[j];
			i++;
			j++;
		}
		else
		{
			A[i] = right[k];
			k++;
			i++;
		}
	}
	//now after we finish the loop it will exit after it satisfies
	//the first or second condition. Now we have some elements left in either
	//array that we need to push it on the original array
	while (j < nleft)
	{
		A[i] = left[j];
		j++;
		i++;
	}
	while (k < nright)
	{
		A[i] = right[k];
		k++; i++;
	}
}
//this array will split array into many sub arrays using recursion
void split(int array[],int n)
{
	int mid = n/2;
	int* left = (int*)malloc(mid * sizeof(int));
	int* right = (int*)malloc((n - mid) * sizeof(int));
	//we need base case. If there is only 1 element in the array
	//we return;
	if (n < 2)
		return;
	for (int i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (int j = mid; j < n; j++)
	{
		right[j-mid] = array[j];
	}
	split(left,mid); //now we have left sublist
	split(right,n-mid); //right sublist
	merge(array, left, mid, right, n- mid); //merge them back after spliting and sort it
	delete(left);
	delete(right);
}
int main()
{
	int array[20] = {2,5,3,7,9,8,1,0};
	split(array,8);
	for (int i = 0; i < 8; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}