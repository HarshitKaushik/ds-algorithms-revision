#include <iostream>
using namespace std;

// Print array a of size n
void printArray(int a[], int n) {
  for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// Function to reverse an array from startIndex to endIndex
void reverseArray(int a[], int startIndex, int endIndex) {
  while (startIndex < endIndex) {
    int temp = a[startIndex];
    a[startIndex] = a[endIndex];
    a[endIndex] = temp;
    startIndex++;
    endIndex--;
  }
}

void leftRotate(int a[], int d, int n) {
  reverseArray(a, 0, d - 1);
  reverseArray(a, d, n - 1);
  reverseArray(a, 0, n - 1);
}

int main() {
  // Array Rotation
  // Reversal algorithm
  // (ArBr)r = BA
  int a[] = { 1,2,3,4,5,6,7,8,9,10 };
  int n = 10;
  leftRotate(a, 3, 10);
  printArray(a, 10);
  return 0;
}

