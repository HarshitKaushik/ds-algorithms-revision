#include <iostream>
using namespace std;

// Algorithm to right rotate an array of size n by k positions using reversal algorithms
// Reference link: https://www.geeksforgeeks.org/reversal-algorithm-right-rotation-array/

// Algo

// rotate(arr[], d, n)
//   reverseArray(arr[], 0, n - 1);
//   reverse(arr[], 0, d - 1);
//   reverse(arr[], d, n - 1);

// Print array a of size n
void printArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

// Function to reverse an array from startIndex to endIndex
void reverseArray(int a[], int startIndex, int endIndex)
{
  while (startIndex < endIndex)
  {
    int temp = a[startIndex];
    a[startIndex] = a[endIndex];
    a[endIndex] = temp;
    startIndex++;
    endIndex--;
  }
}

void rightRotate(int a[], int d, int n)
{
  reverseArray(a, 0, n - 1);
  printArray(a, n);
  reverseArray(a, 0, d - 1);
  printArray(a, n);
  reverseArray(a, d, n-1);
  printArray(a, n);
}

int main()
{
  // Array Rotation
  // Reversal algorithm
  // (ArBr)r = BA
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = 10;
  rightRotate(a, 3, 10);
  return 0;
}
