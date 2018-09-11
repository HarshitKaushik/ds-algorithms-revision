#include <iostream>
using namespace std;

// Replace every array element by multiplication of previous and next
// Given an array of integers, update every element with multiplication of
// previous and next elements with following exceptions.
// a) First element is replaced by multiplication of first and second.
// b) Last element is replaced by multiplication of last and second last.

// Reference link: https://www.geeksforgeeks.org/replace-every-array-element-by-multiplication-of-previous-and-next/

// Implementation
void modify(int arr[], int n)
{
  // Nothing to do when array size is 1
  if (n <= 1)
    return;
  // store current value of arr[0] and update it
  int prev = arr[0];
  arr[0] = arr[0] * arr[1];
  // Update rest of the array elements
  for (int i = 1; i < n - 1; i++)
  {
    // Store current value of next iteration
    int curr = arr[i];
    // Update current value using previos value
    arr[i] = prev * arr[i + 1];
    // Update previous value
    prev = curr;
  }
  // Update last array element
  arr[n - 1] = prev * arr[n - 1];
}

// Driver program
int main()
{
  int arr[] = {2, 3, 4, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  modify(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
  // Output:
  // 6 8 15 24 30
}