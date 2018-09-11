#include <iostream>
using namespace std;

// Rearrange array such that even index elements are smaller and odd index
// elements are greater
// Given an array, rearrange the array such that :
// If index i is even, arr[i] <= arr[i+1]
// If index i is odd, arr[i] >= arr[i+1]
// This problem is similar to sort an array in wave form.

// A simple solution is to sort the array in decreasing order, then starting
// from second element, swap the adjacent elements.

// An efficient solution is to iterate over the array and swap the elements as
// per the given condition.
// If we have an array of length n, then we iterate from index 0 to n-2 and
// check the given condition.
// At any point of time if i is even and arr[i] > arr[i+1], then we swap arr[i]
// and arr[i+1]. Similarly, if i is odd and
// arr[i] < arr[i+1], then we swap arr[i] and arr[i+1].

// CPP code to rearrange an array such that
// even index elements are smaller and odd
// index elements are greater than their
// next.
void rearrange(int *arr, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    if (i % 2 == 0 && arr[i] > arr[i + 1])
      swap(arr[i], arr[i + 1]);
    if (i % 2 != 0 && arr[i] < arr[i + 1])
      swap(arr[i], arr[i + 1]);
  }
}

// Utility that prints out an array
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

/* Driver function to test above functions */
int main()
{
  int arr[] = {6, 4, 2, 1, 8, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Before rearranging: \n";
  printArray(arr, n);
  rearrange(arr, n);
  cout << "After rearranging: \n";
  printArray(arr, n);
  return 0;
  // Output:
  // Before rearranging:
  // 6 4 2 1 8 3
  // After rearranging:
  // 4 6 1 8 2 3
}