#include <iostream>
using namespace std;

// Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’
// Given an array of size n where all elements are distinct and in range from 0
// to n-1, change contents of arr[] so that arr[i] = j is changed to arr[j] = i

// Reference link: https://www.geeksforgeeks.org/rearrange-array-arrj-becomes-arri-j/

// A simple method to rearrange 'arr[0..n-1]' so that 'arr[j]'
// becomes 'i' if 'arr[i]' is 'j'
// Takes O(n) space and O(n) running time
// Naive approach
void rearrangeNaive(int arr[], int n)
{
  // Create an auxiliary array of same size
  int temp[n], i;
  // Store result in temp[]
  for (i = 0; i < n; i++)
    temp[arr[i]] = i;
  // Copy temp back to arr[]
  for (i = 0; i < n; i++)
    arr[i] = temp[i];
}

// Can we solve this in O(n) time and O(1) auxiliary space?
// The idea is based on the fact that the modified array is basically a
// permutation of input array. We can find the target permutation by storing
// the next item before updating it.

// A space efficient program to rearrange contents of
//  arr[] such that arr[j] becomes j if arr[i] is j

// A utility function to rearrange elements in the cycle
// starting at arr[i]. This function assumes values in
// arr[] be from 1 to n. It changes arr[j-1] to i+1
// if arr[i-1] is j+1
void rearrangeUtil(int arr[], int n, int i)
{
  // 'val' is the value to be stored at 'arr[i]'
  int val = -(i + 1);
  // The next value is determined
  // using current index
  i = arr[i] - 1;
  // The next index is determined
  // using current value
  // While all elements in cycle are not processed
  while (arr[i] > 0)
  {
    // Store value at index as it is going to be
    // used as next index
    int new_i = arr[i] - 1;
    // Update arr[]
    arr[i] = val;
    // Update value and index for next iteration
    val = -(i + 1);
    i = new_i;
  }
}

// A space efficient method to rearrange 'arr[0..n-1]'
// so that 'arr[j]' becomes 'i' if 'arr[i]' is 'j'
// O(1) auxiliary space
// O(n) running time
void rearrange(int arr[], int n)
{
  // Increment all values by 1, so that all elements
  // can be made negative to mark them as visited
  int i;
  for (i = 0; i < n; i++)
    arr[i]++;
  // Process all cycles
  for (i = 0; i < n; i++)
  {
    // Process cycle starting at arr[i] if this cycle is
    // not already processed
    if (arr[i] > 0)
      rearrangeUtil(arr, n, i);
  }
  // Change sign and values of arr[] to get the original
  //  values back, i.e., values in range from 0 to n-1
  for (i = 0; i < n; i++)
    arr[i] = (-arr[i]) - 1;
}

// Another Method: The idea is to store each element’s new and old value as
// quotient and remainder of n, respectively (n being the size of the array).
// For example, Suppose an element’s new value is 2, the old value is 1 and n
// is 3, then the element’s value is stored as 1 + 2*3 = 7. We can retrieve its
// old value by 7%3 = 1 and its new value by 7/3 = 2.

// A simple method to rearrange
// 'arr[0..n-1]' so that 'arr[j]'
// becomes 'i' if 'arr[i]' is 'j'
// O(1) auxiliary space and O(n) running time
void rearrangeAnotherApproach(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    // retrieving old value and
    // storing with the new one
    arr[arr[i] % n] += i * n;
    // arr[arr[i]] original value, i new value multiplied by n
  }
  for (int i = 0; i < n; i++)
  {
    // retrieving new value
    arr[i] /= n;
  }
}

// A utility function to print contents of arr[0..n-1]
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program int main()
int main()
{
  int arr[] = {1, 3, 0, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Given array is \n");
  printArray(arr, n);
  rearrangeNaive(arr, n);
  printf("Modified array is \n");
  printArray(arr, n);
  // Given array is
  // 1 3 0 2
  // Modified array is
  // 2 0 3 1
  int arr2[] = {1, 3, 0, 2};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  printf("Given array is \n");
  printArray(arr2, n2);
  rearrange(arr2, n2);
  printf("Modified array is \n");
  printArray(arr2, n2);
  // Given array is
  // 1 3 0 2
  // Modified array is
  // 2 0 3 1
  int arr3[] = {1, 3, 0, 2};
  int n3 = sizeof(arr3) / sizeof(arr3[0]);
  printf("Given array is \n");
  printArray(arr3, n3);
  rearrangeAnotherApproach(arr3, n3);
  printf("Modified array is \n");
  printArray(arr3, n3);
  // Given array is
  // 1 3 0 2
  // Modified array is
  // 2 0 3 1
  return 0;
}