#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

// K’th Smallest Element in Unsorted Array
// Given an array and a number k where k is smaller than size of array, we need
// to find the k’th smallest element in the given array. It is given that all
// array elements are distinct

// Reference links: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

// Input: arr[] = {7, 10, 4, 3, 20, 15}
// k = 3
// Output: 7

// Approach 1:
// A Simple Solution is to sort the given array using a O(nlogn) sorting
// algorithm like Merge Sort, Heap Sort, etc and return the element at index
// k-1 in the sorted array. Time Complexity of this solution is O(n Log n)

// Method to swap the integer values
void swapValues(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

// Partition method to place last element in its right place in the array. All smaller and equal elements before it
// and all greater elements after it
int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swapValues(&array[i], &array[j]);
    }
  }
  // Place pivot in its right place
  swapValues(&array[i + 1], &array[high]);
  return (i + 1);
}

// Recursive quick sort algorithm
void quickSort(int array[], int low, int high)
{
  // low is lower index and high is upper index
  // taking the last element as pivot
  if (low < high)
  {
    int partitioningIndex = partition(array, low, high);
    quickSort(array, low, partitioningIndex - 1);
    quickSort(array, partitioningIndex + 1, high);
  }
}

// Approach 2:

// We can find k’th smallest element in time complexity better than O(n Log n).A
// simple optomization is to create a Min Heap of the given n elements and call
// extractMin() k times.

// Time complexity of this solution is O(n + kLogn).

// A class for Min Heap
class MinHeap
{
  int *harr;    // pointer to array of elements in heap
  int capacity; // maximum possible size of min heap
  int heapSize; // Current number of elements in min heap
public:
  MinHeap(int a[], int size); // Constructor
  void minHeapify(int i);     //To minheapify subtree rooted with index i
  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return (2 * i + 1); }
  int right(int i) { return (2 * i + 2); }

  int extractMin();                // extracts root (minimum) element
  int getMin() { return harr[0]; } // Returns minimum
};

MinHeap::MinHeap(int a[], int size)
{
  heapSize = size;
  harr = a; // store address of array
  int i = (heapSize - 1) / 2;
  while (i >= 0)
  {
    minHeapify(i);
    i--;
  }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
  if (heapSize == 0)
    return 0;
  // Store the minimum value.
  int root = harr[0];
  // If there are more than 1 items, move the last item to root
  // and call heapify.
  if (heapSize > 1)
  {
    harr[0] = harr[heapSize - 1];
    minHeapify(0);
  }
  heapSize--;
  return root;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::minHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < heapSize && harr[l] < harr[i])
    smallest = l;
  if (r < heapSize && harr[r] < harr[smallest])
    smallest = r;
  if (smallest != i)
  {
    swapValues(&harr[i], &harr[smallest]);
    minHeapify(smallest);
  }
}

// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
  // Build a heap of n elements: O(n) time
  MinHeap mh(arr, n);
  // Do extract min (k-1) times
  for (int i = 0; i < k - 1; i++)
    mh.extractMin();
  // Return root
  return mh.getMin();
}

// Approach 3
// We can also use Max Heap for finding the k’th smallest element. Following is algorithm.
// Build a Max-Heap MH of the first k elements (arr[0] to arr[k-1]) of the given array. O(k)
// For each element, after the k’th element (arr[k] to arr[n-1]), compare it with root of MH
// If the element is less than the root then make it root and call heapify for MH
// Else ignore it
// Finally, root of the MH is the kth smallest element.
// Time complexity of this solution is O(k + (n - k) * log k)

// A class for Max Heap
class MaxHeap
{
  int *harr;    // pointer to array of elements in heap
  int capacity; // maximum possible size of max heap
  int heapSize; // Current number of elements in max heap
public:
  MaxHeap(int a[], int size); // Constructor
  void maxHeapify(int i);     //To maxHeapify subtree rooted with index i
  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return (2 * i + 1); }
  int right(int i) { return (2 * i + 2); }

  int extractMax();                // extracts root (maximum) element
  int getMax() { return harr[0]; } // Returns maximum

  // to replace root with new node x and heapify() new root
  void replaceMax(int x)
  {
    harr[0] = x;
    maxHeapify(0);
  }
};

MaxHeap::MaxHeap(int a[], int size)
{
  heapSize = size;
  harr = a; // store address of array
  int i = (heapSize - 1) / 2;
  while (i >= 0)
  {
    maxHeapify(i);
    i--;
  }
}

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
  if (heapSize == 0)
    return 0;
  // Store the maximum value.
  int root = harr[0];
  // If there are more than 1 items, move the last item to root
  // and call heapify.
  if (heapSize > 1)
  {
    harr[0] = harr[heapSize - 1];
    maxHeapify(0);
  }
  heapSize--;
  return root;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::maxHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int largest = i;
  if (l < heapSize && harr[l] > harr[i])
    largest = l;
  if (r < heapSize && harr[r] > harr[largest])
    largest = r;
  if (largest != i)
  {
    swapValues(&harr[i], &harr[largest]);
    maxHeapify(largest);
  }
}

// Function to return kth smallest element in a given array
int kthSmallestFromMaxHeap(int arr[], int n, int k)
{
  // Build a heap of first k elements: O(k) time
  MaxHeap mh(arr, k);
  // Process remaining n-k elements.  If current element is
  // smaller than root, replace root with current element
  for (int i = k; i < n; i++)
    if (arr[i] < mh.getMax())
      mh.replaceMax(arr[i]);
  // Return root
  return mh.getMax();
}

// Approach 4

// Randomized QuickSelect algorithm
// The idea is to randomly pick a pivot element. To implement randomized
// partition, we use a random function, rand() to generate index between l and
// r, swap the element at randomly generated index with the last element, and
// finally call the standard partition process which uses last element as pivot.

// The worst case time complexity of the above solution is still O(n^2). In
// worst case, the randomized function may always pick a corner element. The
// expected time complexity of above randomized QuickSelect is O(n)

int randomPartition(int arr[], int l, int r);

// This function returns kth smallest element in arr[l..r] using
// QuickSort based method.
// ASSUMPTION: ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallestRandomizedQuickSelect(int arr[], int l, int r, int k)
{
  // If k is smaller than number of elements in array
  if (k > 0 && k <= r - l + 1)
  {
    // Partition the array around a random element and
    // get position of pivot element in sorted array
    int pos = randomPartition(arr, l, r);
    // If position is same as k
    if (pos - l == k - 1)
      return arr[pos];
    // If position is more, recur for left subarray
    if (pos - l > k - 1)
      return kthSmallestRandomizedQuickSelect(arr, l, pos - 1, k);
    // Else recur for right subarray
    return kthSmallestRandomizedQuickSelect(arr, pos + 1, r, k - pos + l - 1);
  }
  // If k is more than the number of elements in the array
  return INT_MAX;
}

// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it and
// greater elements to right. This function is used by randomPartition()
int partitionQuickSort(int arr[], int l, int r)
{
  int x = arr[r], i = l;
  for (int j = l; j <= r - 1; j++)
  {
    if (arr[j] <= x)
    {
      swapValues(&arr[i], &arr[j]);
      i++;
    }
  }
  swapValues(&arr[i], &arr[r]);
  return i;
}

// Picks a random pivot element between l and r and partitions
// arr[l..r] around the randomly picked element using partition()
int randomPartition(int arr[], int l, int r)
{
  int n = r - l + 1;
  int pivot = rand() % n;
  swapValues(&arr[l + pivot], &arr[r]);
  return partitionQuickSort(arr, l, r);
}

// 

// Driver program
int main()
{
  int testArray[] = {7, 10, 4, 3, 20, 15};
  int size = 6;
  int k = 3;
  quickSort(testArray, 0, size - 1);
  cout << "The kth smallest element:\n"
       << testArray[k - 1] << endl;
  // Output:
  // The kth smallest element:
  // 7
  int testArray2[] = {7, 10, 4, 3, 20, 15};
  int size2 = 6;
  int k2 = 3;
  int kthMin = kthSmallest(testArray2, size2, k2);
  cout << "The kth smallest element:\n"
       << kthMin << endl;
  // Output:
  // The kth smallest element:
  // 7
  int testArray3[] = {7, 10, 4, 3, 20, 15};
  int size3 = 6;
  int k3 = 3;
  int kthMin2 = kthSmallestFromMaxHeap(testArray3, size3, k3);
  cout << "The kth smallest element:\n"
       << kthMin2 << endl;
  // Output:
  // The kth smallest element:
  // 7
  int testArray4[] = {7, 10, 4, 3, 20, 15};
  int size4 = 6;
  int k4 = 3;
  int kthMin3 = kthSmallestRandomizedQuickSelect(testArray4, 0, size4 - 1, k4);
  cout << "The kth smallest element:\n"
       << kthMin3 << endl;
  // Output:
  // The kth smallest element:
  // 7
  return 0;
}