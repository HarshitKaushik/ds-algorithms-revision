#include <iostream>
using namespace std;

// Bubble Sort
// Bubble Sort is the simplest sorting algorithm that works by repeatedly
// swapping the adjacent elements if they are in wrong order.
// Reference link: https://www.geeksforgeeks.org/bubble-sort/

// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
// Sorting In Place: Yes
// Stable: Yes

// Method to swap the integer values
void swapValues(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

// Function to bubble sort an array
void bubbleSort(int array[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    bool swap = false;
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (array[j] > array[j + 1])
      {
        swapValues(&array[j], &array[j + 1]);
        swap = true;
      }
    }
    if (!swap)
    {
      // Already sorted array
      // break
    }
  }
}

// Driver function
int main()
{
  int array[] = {6, 8, 9, 10, 1, 2, 4, 5, 6, 7};
  int size = 10;
  cout << "The Original Array: ";
  for(int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  bubbleSort(array, size);
  cout << "The Sorted Array: ";
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
  // Output:
  // The Original Array: 6 8 9 10 1 2 4 5 6 7
  // The Sorted Array: 1 2 4 5 6 6 7 8 9 10
}