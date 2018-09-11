#include <iostream>
using namespace std;

// Rearrange an array in maximum minimum form in O(1) extra space
// Given a sorted array of positive integers, rearrange the array alternately
// i.e first element should be the maximum value, second minimum value,
// third-second max, fourth-second min and so on
// Reference link: https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/

// Input  : arr[] = {1, 2, 3, 4, 5, 6, 7}
// Output : arr[] = {7, 1, 6, 2, 5, 3, 4}

// Prints max at first position, min at second position
// second max at third position, second min at fourth
// position and so on.
// This assumes that the given array is already sorted.
void rearrange(int arr[], int n)
{
  // initialize index of first minimum and first
  // maximum element
  int maxIndex = n - 1;
  int minIndex = 0;
  // store maximum element of array
  int maxElement = arr[n - 1] + 1;
  // traverse array elements
  for (int i = 0; i < n; i++)
  {
    // at even index : we have to put maximum element
    if (i % 2 == 0)
    {
      arr[i] += (arr[maxIndex] % maxElement) * maxElement;
      maxIndex--;
    }
    // at odd index : we have to put minimum element
    else
    {
      arr[i] += (arr[minIndex] % maxElement) * maxElement;
      minIndex++;
    }
  }
  // array elements back to it's original form
  for (int i = 0; i < n; i++)
    arr[i] = arr[i] / maxElement;
}

// Driver program to test above function
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Original Array\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  rearrange(arr, n);
  cout << "\nModified Array\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
  // Output:
  // Original Array
  // 1 2 3 4 5 6 7 8 9
  // Modified Array
  // 9 1 8 2 7 3 6 4 5
}