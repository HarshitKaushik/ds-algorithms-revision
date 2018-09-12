#include <iostream>
using namespace std;

// K’th Smallest Element in Unsorted Array
// Given an array and a number k where k is smaller than size of array, we need
// to find the k’th smallest element in the given array. It is given that all
// array elements are distinct

// Reference link: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

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
  int *harr;     // pointer to array of elements in heap
  int capacity;  // maximum possible size of max heap
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
  return 0;
}