// Find the Rotation Count in Rotated Sorted array
// Reference: https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  // test sorted array in ascending order right rotated by three places
  // We can observe in this case, the index of smallest number is the
  // number of right rotations
  // We can find the minimum number in worst case O(n) running time
  int arr[] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);
  int smallestElementIndex = 0;
  for (int i = 1; i <= n - 1; i++)
    if (arr[i] < arr[i - 1])
    {
      smallestElementIndex = i;
      break;
    }
  cout << smallestElementIndex;
  // Output
  // 3
  return 0;
}
