#include <iostream>
using namespace std;

// Maximum Sum Path in Two Arrays
// Given two sorted arrays such the arrays may have some common elements. Find
// the sum of the maximum sum path to reach from beginning of any array to end
// of any of the two arrays. We can switch from one array to another array only
// at common elements.

// Expected time complexity is O(m + n) where m is the number of elements in ar1[]
// and n is the number of elements in ar2[].
// Reference link: https://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/

// Input:  ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}
// ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
// Output: 122
// 122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34

// We can approach this problem by initializing result = 0, sum1 = 0 and sum2 = 0
// Loop both the arrays at same indexes, if not a common point, add sum1 += a[i]
// and sum2 += b[i] and if a common point sum += max(sum1, sum2) + a[i]
// After a common point reset sum1 and sum2

// Utility function to find maximum of two integers
int max(int x, int y) { return (x > y) ? x : y; }

// This function returns the sum of elements on maximum path
// from beginning to end
int maxPathSum(int ar1[], int ar2[], int m, int n)
{
  // initialize indexes for ar1[] and ar2[]
  int i = 0, j = 0;
  // Initialize result and current sum through ar1[] and ar2[].
  int result = 0, sum1 = 0, sum2 = 0;
  // Below 3 loops are similar to merge in merge sort
  cout << "result: " << result << endl;
  cout << "sum1: " << sum1 << endl;
  cout << "sum2: " << sum2 << endl;
  cout << "m: " << m << endl;
  cout << "n: " << n << endl;
  while (i < m && j < n)
  {
    cout << "Iteration begins" << endl;
    cout << "i: " << i << "\nj: " << j << endl;
    // Add elements of ar1[] to sum1
    cout << "array elements ar1[i] = " << ar1[i] << endl;
    cout << "array elements ar2[j] = " << ar2[j] << endl;
    if (ar1[i] < ar2[j])
    {
      sum1 += ar1[i++];
      cout << "sum1 :" << sum1 << endl;
    }
    // Add elements of ar2[] to sum2
    else if (ar1[i] > ar2[j])
    {
      sum2 += ar2[j++];
      cout << "sum2: " << sum2 << endl;
    }
    else // we reached a common point
    {
      // Take the maximum of two sums and add to result
      result += max(sum1, sum2);
      cout << "result: " << result << endl;
      // Update sum1 and sum2 for elements after this
      // intersection point
      sum1 = 0, sum2 = 0;
      // Keep updating result while there are more common
      // elements
      while (i < m && j < n && ar1[i] == ar2[j])
      {
        cout << "Same element: " << ar1[i] << endl;
        result = result + ar1[i];
        cout << "result: " << result << endl;
        i++;
        j++;
      }
    }
  }
  // Add remaining elements of ar1[]
  while (i < m)
  {
    cout << "Remaining elements of ar1" << endl;
    sum1 += ar1[i++];
    cout << "sum1 :" << sum1 << endl;
  }
  // Add remaining elements of ar2[]
  while (j < n)
  {
    cout << "Remaining elements of ar2" << endl;
    sum2 += ar2[j++];
    cout << "sum2: " << sum2 << endl;
  }
  // Add maximum of two sums of remaining elements
  cout << "Final comparison" << endl;
  cout << "sum1: " << sum1 << endl;
  cout << "sum2: " << sum2 << endl;
  result += max(sum1, sum2);
  cout << "result: " << result << endl;
  return result;
}

// Driver program to test above function
int main()
{
  int ar1[] = {2, 3, 7, 10, 12, 15, 30, 34};
  int ar2[] = {1, 5, 7, 8, 10, 15, 16, 19};
  int m = sizeof(ar1) / sizeof(ar1[0]);
  int n = sizeof(ar2) / sizeof(ar2[0]);
  cout << "Maximum sum path is "
       << maxPathSum(ar1, ar2, m, n);
  return 0;
}