#include <iostream>
using namespace std;

// Window sliding technique
// This technique shows how a nested for loop in few problems can be converted
// to single for loop and hence reducing the time complexity.

// Reference link: https://www.geeksforgeeks.org/window-sliding-technique/

// Reference problem:
// Given an array of integers of size ‘n’.
// Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the
// array.

// Input: arr[] = {100, 200, 300, 400} and k = 2
// Output: 700

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
  // k must be greater
  if (n < k)
  {
    cout << "Invalid";
    return -1;
  }
  // Compute sum of first window of size k
  int max_sum = 0;
  for (int i = 0; i < k; i++)
    max_sum += arr[i];
  // Compute sums of remaining windows by
  // removing first element of previous
  // window and adding last element of
  // current window.
  int window_sum = max_sum;
  for (int i = k; i < n; i++)
  {
    window_sum += arr[i] - arr[i - k];
    max_sum = max(max_sum, window_sum);
  }
  return max_sum;
}

// Driver code
int main()
{
  int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
  int k = 4;
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << maxSum(arr, n, k);
  // Output:
  // 24
  return 0;
}