#include <iostream>
using namespace std;

// Quickly find multiple left rotations of an array
// Write algorithms to quickly find the n left or right rotations of an array
// Reference link: https://www.geeksforgeeks.org/quickly-find-multiple-left-rotations-of-an-array/

// A space optimised solution to the problem

// Function to left rotate an array k times
void leftRotate(int arr[], int n, int k)
{
  // Print array after k rotations
  for (int i = k; i < k + n; i++)
    cout << arr[i % n] << " ";
  // Modular arithmetic magic
  cout << endl;
}

int main()
{
  int arr[] = {1, 3, 5, 7, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 2;
  leftRotate(arr, n, k);
  k = 3;
  leftRotate(arr, n, k);
  k = 4;
  leftRotate(arr, n, k);
  return 0;
}
