#include <iostream>
using namespace std;

// Segregate 0s and 1s in an array
// You are given an array of 0s and 1s in random order. Segregate 0s on left
// side and 1s on right side of the array. Traverse array only once.
// Reference link: https://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
// Maintain two indexes. Initialize first index left as 0 and second index
// right as n-1.

// Do following while left < right
// a) Keep incrementing index left while there are 0s at it
// b) Keep decrementing index right while there are 1s at it
// c) If left < right then exchange arr[left] and arr[right]

// Algorithm traverses the array only once and runs in O(n) time.

// Function to put all 0s on left and all 1s on right
void segregate0and1(int arr[], int size)
{
  /* Initialize left and right indexes */
  int left = 0, right = size - 1;
  while (left < right)
  {
    /* Increment left index while we see 0 at left */
    while (arr[left] == 0 && left < right)
      left++;
    /* Decrement right index while we see 1 at right */
    while (arr[right] == 1 && left < right)
      right--;
    /* If left is smaller than right then there is a 1 at left
          and a 0 at right.  Exchange arr[left] and arr[right]*/
    if (left < right)
    {
      arr[left] = 0;
      arr[right] = 1;
      left++;
      right--;
    }
  }
}

// driver program to test
int main()
{
  int arr[] = {0, 1, 0, 1, 1, 0};
  int i, arr_size = sizeof(arr) / sizeof(arr[0]);
  segregate0and1(arr, arr_size);
  printf("Array after segregation\n");
  for (i = 0; i < 6; i++)
    printf("%d ", arr[i]);
  return 0;
  // Output:
  // Array after segregation
  // 0 0 0 1 1 1
}
