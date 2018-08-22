#include <iostream>
using namespace std;

// Given an array A[] and a number x, check for pair in A[] with sum as x
// https://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/

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

int main()
{
  int arraySize = 10;
  int testArray[] = { 8, 9 , 7, 4, 7, 2, 4, 1, 6, 9 };
  int sumOfPair = 18;
  quickSort(testArray, 0, arraySize - 1);
  int i = 0;
  int j = arraySize - 1;
  while(i < j) {
    if (testArray[i] + testArray[j] == sumOfPair) {
      cout << testArray[i] << " " << testArray[j] << endl;
      break;
    } else if (testArray[i] + testArray[j] < sumOfPair) {
      i++;
    } else {
      j++;
    }
  }
  // Output
  // 9 9
  return 0;
}
