#include <iostream>
#include <algorithm>
using namespace std;

// Rearrange positive and negative numbers using inbuilt sort function
// Given an array of positive and negative numbers, arrange them such that all
// negative integers appear before all the positive integers in the array
// without using any additional data structure like hash table, arrays, etc.
// The order of appearance should be maintained.

// In c++ STL, There is an inbuilt function std::sort(). We can modify the comp
// () function to obtain the desired result. As we have to place negative
// numbers first and then positive numbers.

// Reference link: https://www.geeksforgeeks.org/rearrange-positive-negative-numbers-using-inbuilt-sort-function/

bool comp(int a, int b)
{
  // This is to maintain order
  if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
    return false;
  // No swapping required when one is 0
  if (a == 0)
    return true;
  // Swapping is must
  if ((a >= 0) && (b < 0))
    return false;
}

void rearrange(int arr[], int n)
{
  sort(arr, arr + n, comp);
}

// Driver code
int main()
{
  int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
  int n = sizeof(arr) / sizeof(arr[0]);
  rearrange(arr, n);
  for (int i = 0; i < n; i++)
    cout << " " << arr[i];
  return 0;
}
