#include <iostream>
#include <cstdio>
using namespace std;

// Rearrange positive and negative numbers with constant extra space
// Given an array of positive and negative numbers, arrange them such that all
// negative integers appear before all the positive integers in the array
// without using any additional data structure like hash table, arrays, etc.The
// order of appearance should be maintained.

// Reference Link: https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/

/* Function to print an array */
void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

/* Function to reverse an array. An array can be
reversed in O(n) time and O(1) space. */
void reverse(int array[], int l, int r)
{
  if (l < r)
  {
    swap(array[l], array[r]);
    // Call recursively till mid element
    reverse(array, ++l, --r);
  }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
  // Initial index of 1st subarray
  int i = l;
  // Initial index of 2nd subarray
  int j = m + 1;
  while (i <= m && arr[i] < 0)
    i++;
  // arr[i..m] is positive
  while (j <= r && arr[j] < 0)
    j++;
  // arr[j..r] is positive
  // reverse positive part of left sub-array (arr[i..m])
  reverse(arr, i, m);
  // reverse negative part of right sub-array (arr[m+1..j-1])
  reverse(arr, m + 1, j - 1);
  // reverse arr[i..j-1]
  reverse(arr, i, j - 1);
}

// Function to rearrange positive and negative
// numbers in a array
void rearrangePositiveNegativeNumbers(int arr[], int l, int r)
{
  if (l < r)
  {
    // Same as (l + r) / 2, but avoids overflow for
    // large l and h
    int m = l + (r - l) / 2;
    // Sort first and second halves
    rearrangePositiveNegativeNumbers(arr, l, m);
    rearrangePositiveNegativeNumbers(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

// Driver program
int main()
{
  int testArray[] = {2, 4, -1, 6, -3, -7, 8, 9};
  int n = 8;
  // Correct output
  // {-1, -3, -7, 2, 4, 6, 8, 9}
  // Quick sort is not a relative sort. Hence, we cannot use a Quick sort like
  // Partition method with 0 as a pivot.

  // Approach 2 : Optimized merge sort
  // Merge method of standard merge sort algorithm can be modified to solve
  // this problem. While merging two sorted halves say left and right, we need
  // to merge in such a way that negative part of left and right sub-array is
  // copied first followed by positive part of left and right sub-array.

  // Time complexity of above solution is O(n log n). The problem with this
  // approach is we are using auxiliary array for merging but we’re not allowed
  // to use any data structure to solve this problem. We can do merging
  // in-place without using any data-structure.
  rearrangePositiveNegativeNumbers(testArray, 0, n - 1);
  printArray(testArray, n);
  // -1 -3 -7 2 4 6 8 9
  return 0;
}
