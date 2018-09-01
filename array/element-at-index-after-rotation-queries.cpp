#include <iostream>
using namespace std;

// Find element at given index after a number of rotations
// An array consisting of N integers is given. There are several left circular
// Rotations of range[L..R] that we perform. After performing these rotations,
// we need to find element at a given index.

// Reference link: https://www.geeksforgeeks.org/find-element-given-index-number-rotations/

// Function to compute the element at
// given index
int findElement(int arr[], int ranges[][2], int rotations, int index)
{
  for (int i = rotations - 1; i >= 0; i--)
  {
    // Range[left...right]
    int left = ranges[i][0];
    int right = ranges[i][1];
    // Rotation will not have any effect
    if (left <= index && right >= index)
    {
      if (index == left)
        index = right;
      else
        index--;
    }
  }
  // Returning new element
  return arr[index];
}

// Driver
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  // No. of rotations
  int rotations = 2;
  // Ranges according to 0-based indexing
  int ranges[rotations][2] = {{0, 2}, {0, 3}};
  int index = 1;
  cout << findElement(arr, ranges, rotations, index);
  return 0;
}