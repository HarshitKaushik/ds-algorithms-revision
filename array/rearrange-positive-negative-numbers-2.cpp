#include <iostream>
#include <cstdio>
using namespace std;

// Rearrange positive and negative numbers with constant extra space
// Given an array of positive and negative numbers, arrange them such that all
// negative integers appear before all the positive integers in the array
// without using any additional data structure like hash table, arrays, etc.The
// order of appearance should be maintained.

// Reference Link: https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/

// Driver program
int main()
{
  int testArray[] = {2, 4, -1, 6, -3, -7, 8, 9};
  int n = 8;
  // Correct output
  // {-1, -3, -7, 2, 4, 6, 8, 9}
  // Quick sort is not a relative sort. Hence, we cannot use a Quick sort like
  // Partition method with 0 as a pivot.
  // Approach 1 : Use a modified insertion sort which inserts a negative number at the index of first positive number after right shifting the positive numbers.

  for (int i = 1; i < 8; i++)
  {
    int key = testArray[i];
    // if positive do nothing
    if (testArray[i] > 0)
    {
      continue;
    }
    // else shift all the positive numbers by one place right
    // and place key in its right position
    int j = i - 1;
    while (j >= 0 && testArray[j] > 0)
    {
      testArray[j + 1] = testArray[j];
      j--;
    }
    // Put negative element at its right position
    testArray[j + 1] = key;
  }
  for (int k = 0; k < n; k++)
  {
    cout << testArray[k] << " ";
  }
  cout << endl;
  return 0;
  // Time complexity of above solution is O(n2) and auxiliary space is O(1).
  // We have maintained the order of appearance and have not used any other data structure.
}
