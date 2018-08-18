#include <iostream>
using namespace std;

// Quick Sort algorithm
// https://www.geeksforgeeks.org/quick-sort/

// Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.

// Recursive quick sort algorithm
void quickSort(int array[], int low, int high)
{
  // low is lower index and high is upper index
  // taking the last element as pivot
  if (low < high)
  {
    int partitioningIndex = partition(array, low, high);
    quickSort(array, low, partitioningIndex - 1);
    quickSort(array, partitioningIndex + 1, high);
  }
}

// Method to swap the integer values
void swapValues(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

// Partition method to place last element in its right place in the array. All smaller and equal elements before it
// and all greater elements after it
int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swapValues(&array[i], &array[j]);
    }
  }
  // Place pivot in its right place
  swapValues(&array[i + 1], &array[high]);
  return (i + 1);
}

int main()
{
  int testArray[] = { 5, 7, 3, 2, 1, 9, 8, 10, 6, 4 };
  quickSort(testArray, 0, 9);
  for (int i = 0; i < 10; i++) {
    cout << testArray[i] << " ";
  }
  cout << endl;
  return 0;
}
