#include <iostream>
using namespace std;

// Quick Sort Algorithm to sort values by Hoare partition scheme
// Reference link: https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
//  Lomuto’s partition scheme is easy to implement as compare to Hoare scheme.
// This approach takes O(n log n) running time in the best and average cases
// If the worst case, the array is already sorted. It degrades to O(n^2) running time

// Hoare’s Partition Scheme works by initializing two indexes that start at two
// ends, the two indexes move toward each other until an inversion is (A
// smaller value on left side and greater value on right side) found. When an
// inversion is found, two values are swapped and process is repeated.

// Hoare’s scheme is more efficient than Lomuto’s partition scheme because it
// does three times fewer swaps on average, and it creates efficient partitions
// even when all values are equal.
// Like Lomuto’s partition scheme, Hoare partitioning also causes Quicksort to
// degrade to O(n^2) when the input array is already sorted, it also doesn’t
// produce a stable sort.

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low - 1, j = high + 1;
  while (true)
  {
    // Find leftmost element greater than pivot
    do
    {
      i++;
    } while (arr[i] < pivot);
    // Find rightmost element smaller than
    // or equal to pivot
    do
    {
      j--;
    } while (arr[j] > pivot);
    // If two pointers met.
    if (i >= j)
      return j;
    swap(arr[i], arr[j]);
  }
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    /* pi is partitioning index, arr[p] is now
           at right place */
    int pi = partition(arr, low, high);
    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi);
    quickSort(arr, pi + 1, high);
  }
}

/* Function to print an array */
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program to test above functions
int main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n - 1);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
  // Output:
  // Sorted array:
  // 1 5 7 8 9 10
}