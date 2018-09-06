#include <iostream>
using namespace std;

// Double the first element and move zeroes to end

// Given an array of integers of size n. Assume ‘0’ as invalid number and all
// other as valid number. Convert the array in such a way that if next valid
// number is same as current number, double its value and replace the next
// number with 0. After the modification, rearrange the array such that all 0’s
// are shifted to the end.

// Reference link: https://www.geeksforgeeks.org/double-first-element-move-zero-end/

// Approach: First modify the array as mentioned, i.e., if next valid number is
// same as current number, double its value and replace the next number with 0.
// After modifying the array, Move all zeroes to the end of array.

// function which pushes all zeros to end of
// an array.
void pushZerosToEnd(int arr[], int n)
{
  // Count of non-zero elements
  int count = 0;
  // Traverse the array. If element encountered
  // is non-zero, then replace the element at
  // index 'count' with this element
  for (int i = 0; i < n; i++)
    if (arr[i] != 0)
      // here count is incremented
      arr[count++] = arr[i];
  // Now all non-zero elements have been shifted
  // to front and 'count' is set as index of
  // first 0. Make all elements 0 from count
  // to end.
  while (count < n)
    arr[count++] = 0;
}

// function to rearrange the array elements
// after modification
void modifyAndRearrangeArr(int arr[], int n)
{
  // if 'arr[]' contains a single element
  // only
  if (n == 1)
    return;
  // traverse the array
  for (int i = 0; i < n - 1; i++)
  {
    // if true, perform the required modification
    if ((arr[i] != 0) && (arr[i] == arr[i + 1]))
    {
      // double current index value
      arr[i] = 2 * arr[i];
      // put 0 in the next index
      arr[i + 1] = 0;
      // increment by 1 so as to move two
      // indexes ahead during loop iteration
      i++;
    }
  }
  // push all the zeros at the end of 'arr[]'
  pushZerosToEnd(arr, n);
}

// function to print the array elements
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

// Driver program to test above
int main()
{
  int arr[] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Original array: ";
  printArray(arr, n);
  modifyAndRearrangeArr(arr, n);
  cout << "\nModified array: ";
  printArray(arr, n);
  return 0;
  // Output:
  // Original array: 0 2 2 2 0 6 6 0 0 8
  // Modified array : 4 2 12 8 0 0 0 0 0 0
}
