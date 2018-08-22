// C++ program to find number of pairs with
// a given sum in a sorted and rotated array.
// Reference link:
// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
// This modifies Meet In The Middle Algorithm
#include <iostream>
using namespace std;

// This function returns count of number of pairs
// with sum equals to x.
int pairsInSortedRotated(int arr[], int n, int x)
{
  // Find the pivot element. Pivot element
  // is maximum element of array.
  int i;
  for (i = 0; i < n - 1; i++)
    if (arr[i] > arr[i + 1])
      break;
  // l is index of minimum element.
  int l = (i + 1) % n;
  // r is index of maximum element.
  int r = i;
  // Variable to store count of number
  // of pairs.
  int count = 0;
  // Find sum of pair formed by arr[l] and
  // and arr[r] and update l, r and count
  // accordingly.
  while (l != r)
  {
    // If we find a pair with sum x, then
    // increment count, move l and r to
    // next element.
    if (arr[l] + arr[r] == x)
    {
      count++;
      // This condition is required to
      // be checked, otherwise l and r
      // will cross each other and loop
      // will never terminate.
      if (l == (r - 1 + n) % n)
      {
        // say for example when l is 9 and r is 0 and n is 10
        return count;
      }
      l = (l + 1) % n;
      r = (r - 1 + n) % n;
    }
    // If current pair sum is less, move to
    // the higher sum side.
    else if (arr[l] + arr[r] < x)
      l = (l + 1) % n;
    // If current pair sum is greater, move
    // to the lower sum side.
    else
      r = (n + r - 1) % n;
  }
  return count;
}

/* Driver program to test above function */
int main()
{
  int arr[] = {11, 15, 6, 7, 9, 10};
  int sum = 16;
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << pairsInSortedRotated(arr, n, sum);
  // Output
  // 2
  return 0;
}