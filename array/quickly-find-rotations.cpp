#include <iostream>
using namespace std;

// Quickly find multiple left rotations of an array
// Write algorithms to quickly find the n left or right rotations of an array
// Reference link: https://www.geeksforgeeks.org/quickly-find-multiple-left-rotations-of-an-array/

// A simple approach can be using array rotation using reversal algorithm, juggling algorithm, block swap algorithm
// Best of which takes O(n) running time.

// An efficient approach to print an array of size n after k rotations.

// 1. Take an array of size 2n and repeat the array two times from 0 to 2n-1 from original array
// 2. Starting point of the array after k rotations is k % n
// 3. Print the rotated array from (k % n) to (k % n + n)

int main()
{
  int testArray[] = {1, 3, 5, 7, 9};
  int size = 5;
  int tempArray[2 * size];
  for (int i = 0; i < size; i++)
  {
    tempArray[i] = testArray[i];
    tempArray[size + i] = testArray[i];
  }
  int k;
  int offset;
  k = 1;
  offset = k % size;
  for (int i = offset; i < offset + size; i++)
  {
    cout << tempArray[i] << " ";
  }
  cout << endl;
}
