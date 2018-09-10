#include <iostream>
using namespace std;

// 3-Way QuickSort (Dutch National Flag)
// In simple QuickSort algorithm, we select an element as pivot, partition the
// array around pivot and recur for subarrays on left and right of pivot.
// Consider an array which has many redundant elements. For example, {1, 4, 2,
// 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4}. If 4 is picked as pivot in
// Simple QuickSort, we fix only one 4 and recursively process remaining
// occurrences.
// Reference link: https://www.geeksforgeeks.org/3-way-quicksort-dutch-national-flag/

// The idea of 3 way QuickSort is to process all occurrences of pivot and is
// based on Dutch National Flag algorithm.

// In 3 Way QuickSort, an array arr[l..r] is divided in 3 parts:
// a) arr[l..i] elements less than pivot.
// b) arr[i+1..j-1] elements equal to pivot.
// c) arr[j..r] elements greater than pivot.

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// A utility function to print an array
void printarr(int a[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
  printf("\n");
}

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */
// It uses Dutch National Flag Algorithm
void partition(int a[], int low, int high, int &i, int &j)
{
  // To handle 2 elements
  if (high - low <= 1)
  {
    if (a[high] < a[low])
      swap(&a[high], &a[low]);
    i = low;
    j = high;
    return;
  }
  int mid = low;
  int pivot = a[high];
  while (mid <= high)
  {
    if (a[mid] < pivot)
      swap(&a[low++], &a[mid++]);
    else if (a[mid] == pivot)
      mid++;
    else if (a[mid] > pivot)
      swap(&a[mid], &a[high--]);
  }
  //update i and j
  i = low - 1;
  j = mid; //or high-1
}

// 3-way partition based quick sort
void quicksort(int a[], int low, int high)
{
  if (low >= high) //1 or 0 elements
    return;
  int i, j;
  // Note that i and j are passed as reference
  partition(a, low, high, i, j);
  // Recur two halves
  quicksort(a, low, i);
  quicksort(a, j, high);
}

// Driver program
int main()
{
  int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
  int size = sizeof(a) / sizeof(int);
  printarr(a, size);
  quicksort(a, 0, size - 1);
  printarr(a, size);
  return 0;
  // Output:
  // 4 9 4 4 1 9 4 4 9 4 4 1 4
  // 1 1 4 4 4 4 4 4 4 4 9 9 9
}