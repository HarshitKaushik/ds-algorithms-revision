#include <iostream>
using namespace std;

// Quick Sort Algorithm to sort values by Lomuto partition scheme
// Reference link: https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/

//  Lomuto’s partition scheme is easy to implement as compare to Hoare scheme.
// This approach takes O(n log n) running time in the best and average cases
// If the worst case, the array is already sorted. It degrades to O(n^2) running time

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than or
    // equal to pivot
    if (arr[j] <= pivot)
    {
      i++;
      // increment index of smaller element
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
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
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
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
