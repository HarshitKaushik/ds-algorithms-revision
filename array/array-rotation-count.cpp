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

// Finds the index of the minimum element in O(log n) running time
// The minimum element is the only element whose previous is greater than it. If there is no previous element element, then there is no rotation (first element is minimum).
// We check this condition for middle element by comparing it with (mid-1)’th and (mid+1)’th elements.
// If minimum element is not at middle (neither mid nor mid + 1), then
// minimum element lies in either left half or right half.
int findMinimumElementInRotatedSortedArray(int arr[], int low, int high) {
  // This condition is needed to handle the case
  // when array is not rotated at all
  if (high < low)
    return 0;
  // If there is only one element left
  if (high == low)
    return low;
  // Find mid
  int mid = (high + low) / 2;
  // Check if element (mid + 1) is minimum element.
  // Consider the cases like {3, 4, 5, 1, 2}
  if (mid < high && arr[mid + 1] < arr[mid])
    return (mid + 1);
  // Check if mid itself is minimum element
  if (mid > low && arr[mid] < arr[mid - 1])
    return mid;
  // Decide whether we need to go to left half or
  // right half
  if (arr[high] > arr[mid])
    return findMinimumElementInRotatedSortedArray(arr, low, mid - 1);
  return findMinimumElementInRotatedSortedArray(arr, mid + 1, high);
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
  cout << smallestElementIndex << endl;
  // Output
  // 3

  // We can also modify the binary search to find the answer in O(log n) time
  int smallestElementIndexAgain = findMinimumElementInRotatedSortedArray(arr, 0 , n - 1);
  cout << smallestElementIndexAgain << endl;
  return 0;
}
