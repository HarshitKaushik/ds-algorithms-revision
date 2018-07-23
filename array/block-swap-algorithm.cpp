#include <iostream>
using namespace std;

// Print array
void printArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// Swap d elements starting from index firstIndex with d elements starting
// from index secondIndex
void swap(int a[], int firstIndex, int secondIndex, int d) {
  for (int i = 0; i < d; i++) {
    int temp = a[firstIndex + i];
    a[firstIndex + i] = a[secondIndex + i];
    a[secondIndex + i] = temp;
  }
}

// Left rotate an array a[] of size n by d elements
void leftRotate(int a[], int n, int d) {
  // if d is 0 or size of a[]
  if (d == 0 or d == n) {
    return;
  }
  if (n - d == d) {
    swap(a, 0, n-d, d);
    return;
  }
  if (n - d > d) {
    swap(a, 0, n - d, d);
    leftRotate(a, n - d, d);
  } else {
    swap(a, 0, d, n - d);
    // This line is tricky
    leftRotate(a + n - d, d, (2 * d) - n);
  }
}

int main() {
  // Array Rotation
  // Using Block Swap algorithm
  // Uses recursion
  // O(n) complexity
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  int d = 3;
  // Rotate array[] by d elements
  leftRotate(a, 10, 6);
  printArray(a, 10);
  return 0;
}

