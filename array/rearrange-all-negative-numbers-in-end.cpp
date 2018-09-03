#include <bits/stdc++.h>
using namespace std;

// Move all negative elements to end in order with extra space allowed
// Given an unsorted array of both negative and positive integers. The task is
// place all negative element at the end of array without changing the order of
// positive element and negative element.
// Very easy if extra space is allowed and can be done O(n) time.

// Reference link: https://www.geeksforgeeks.org/move-ve-elements-end-order-extra-space-allowed/

// Moves all -ve element to end of array in
// same order.
void segregateElements(int arr[], int n)
{
  // Create an empty array to store result
  int temp[n];
  // Traverse array and store +ve element in
  // temp array
  int j = 0;
  for (int i = 0; i < n; i++)
    if (arr[i] >= 0)
      temp[j++] = arr[i];
  // If array contains all positive or all negative.
  if (j == n || j == 0)
    return;
  // Store -ve element in temp array
  for (int i = 0; i < n; i++)
    if (arr[i] < 0)
      temp[j++] = arr[i];
  // Copy contents of temp[] to arr[]
  memcpy(arr, temp, sizeof(temp));
}

// Driver program
int main()
{
  int arr[] = {1, -1, -3, -2, 7, 5, 11, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  segregateElements(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
  // Output:
  // 1 7 5 11 6 -1 -3 -2
}