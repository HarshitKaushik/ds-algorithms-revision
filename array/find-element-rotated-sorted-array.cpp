#include <iostream>
using namespace std;

// An element in a sorted array can be found in O(log n) time via binary search.
// But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand.
// So for instance, 1 2 3 4 5 might become 3 4 5 1 2.
// Devise a way to find an element in the rotated array in O(log n) time.
// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

// Function for binary search in O(log n) running time
int binarySearch(int array[], int key, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (key == array[mid]) {
    return mid;
  }
  if (key > array[mid]) {
    return binarySearch(array, (mid + 1), high, key);
  }
  return binarySearch(array, low, (mid - 1), key);
}

// function to find pivot in a sorted and rotated array
// pivot is the index of the maximum value in the array
int pivotSearch(int array[], int low, int high) {
  // handle base cases
  if (high < low) {
    return -1;
  }
  if (low == high) {
    return low;
  }
  int mid = low + high / 2;
  if (mid < high && array[mid] > array[mid + 1]) {
    return mid;
  } else if (mid > low && array[mid - 1] > array[mid]) {
    return mid - 1;
  }
  if (array[low] >= array[mid]) {
    return pivotSearch(array, low, mid - 1);
  }
  return pivotSearch(array, mid + 1, high);
}

// Finds key in rotated sorted array[] in O(log n)
int pivotedBinarySearch(int array[], int key, int size) {
  int pivot = pivotSearch(array, 0, size - 1);

  // If we didn't find a pivot,
  // then array is not rotated at all
  if (pivot == -1) {
    return binarySearch(array, key, 0, size - 1);
  }

  // If we found a pivot, then first compare with pivot
  // and then search in two subarrays around pivot
  if (array[pivot] == key) {
    return pivot;
  }

  if (array[0] <= key)
    return binarySearch(array, key, 0, pivot - 1);

  return binarySearch(array, key, pivot + 1, size - 1);
}

int main()
{
  int testArray[] = { 4,5,6,7,1,2,3 };
  int size = 7;
  int numberToFind = 5;
  cout << pivotedBinarySearch(testArray, numberToFind, size) << endl;
  // 1
  return 0;
}
