#include <iostream>
using namespace std;

// Move all zeroes to end of array
// Given an array of n numbers. The problem is to move all the 0’s to the end
// of the array while maintaining the order of the other elements. Only single
// traversal of the array is required.

// Reference link: https://www.geeksforgeeks.org/move-zeroes-end-array-set-2-using-single-traversal/

// Solves the problem in O(n) running time and O(1) space.

// function to move all zeroes at
// the end of array
void moveZeroesToEnd(int arr[], int n)
{
  // Count of non-zero elements
  int count = 0;
  // Traverse the array. If arr[i] is non-zero, then
  // swap the element at index 'count' with the
  // element at index 'i'
  for (int i = 0; i < n; i++)
    if (arr[i] != 0)
      swap(arr[count++], arr[i]);
}

// function to print the array elements
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver program to test above
int main()
{
  int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Original array: ";
  printArray(arr, n);
  moveZeroesToEnd(arr, n);
  cout << "\nModified array: ";
  printArray(arr, n);
  return 0;
  // Original array: 0 1 9 8 4 0 0 2 7 0 6 0 9
  // Modified array: 1 9 8 4 2 7 6 9 0 0 0 0 0
}