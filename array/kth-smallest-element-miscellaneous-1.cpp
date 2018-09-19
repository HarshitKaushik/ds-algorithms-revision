#include <iostream>
#include <climits>
using namespace std;

// kth smallest element in a row - wise and column - wise sorted 2D array
// Given an n x n matrix, where every row and column is sorted in
// non-decreasing order. Find the kth smallest element in the given 2D array.

// Reference link: https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/

// 10, 20, 30, 40
// 15, 25, 35, 45
// 24, 29, 37, 48
// 32, 33, 39, 50
// The 3rd smallest element is 20 and 7th smallest element is 30

// The idea is to use min heap. Build a min heap of elements from first row. A heap entry also stores row number and column number.
// Do following k times.
// a) Get minimum element (or root) from min heap.
// b) Find row number and column number of the minimum element.
// c) Replace root with the next element from same column and min-heapify the root.
// Return the last extracted root.

// A structure to store an entry of heap. The entry contains
// a value from 2D array, row and column numbers of the value
struct HeapNode
{
  int val; // value to be stored
  int r;   // Row number of value in 2D array
  int c;   // Column number of value in 2D array
};

// A utility function to swap two HeapNode items.
void swap(HeapNode *x, HeapNode *y)
{
  HeapNode z = *x;
  *x = *y;
  *y = z;
}

// A utility function to minheapify the node harr[i] of a heap
// stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
  int l = i * 2 + 1;
  int r = i * 2 + 2;
  int smallest = i;
  if (l < heap_size && harr[l].val < harr[i].val)
    smallest = l;
  if (r < heap_size && harr[r].val < harr[smallest].val)
    smallest = r;
  if (smallest != i)
  {
    swap(&harr[i], &harr[smallest]);
    minHeapify(harr, smallest, heap_size);
  }
}

// A utility function to convert harr[] to a min heap
void buildHeap(HeapNode harr[], int n)
{
  int i = (n - 1) / 2;
  while (i >= 0)
  {
    minHeapify(harr, i, n);
    i--;
  }
}

// This function returns kth smallest element in a 2D array mat[][]
int kthSmallest(int *mat, int n, int k)
{
  // k must be greater than 0 and smaller than n * n
  if (k <= 0 || k > n * n)
    return INT_MAX;
  // Create a min heap of elements from first row of 2D array
  HeapNode harr[n];
  for (int i = 0; i < n; i++)
    harr[i] = {*(mat + 0 * n + i), 0, i};
  buildHeap(harr, n);
  HeapNode hr;
  for (int i = 0; i < k; i++)
  {
    // Get current heap root
    hr = harr[0];
    // Get next value from column of root's value. If the
    // value stored at root was last value in its column,
    // then assign INFINITE as next value
    int nextval = (hr.r < (n - 1)) ? *(mat + (hr.r + 1) * n + hr.c) : INT_MAX;
    // Update heap root with next value
    harr[0] = {nextval, (hr.r) + 1, hr.c};
    // Heapify root
    minHeapify(harr, 0, n);
  }
  // Return the value at last extracted root
  return hr.val;
}

// driver program to test above function
int main()
{
  int mat[4][4] = {
      {10, 20, 30, 40},
      {15, 25, 35, 45},
      {25, 29, 37, 48},
      {32, 33, 39, 50},
  };
  cout << "7th smallest element is " << kthSmallest(&mat[0][0], 4, 7);
  return 0;
  // Output:
  // 7th smallest element is 30
}