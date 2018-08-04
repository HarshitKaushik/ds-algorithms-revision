#include <iostream>
using namespace std;

int main()
{  
  // Find an element in a rotated sorted array in O(log n) running time
  // O(log n) complexity
  // Assuming that all numbers here are different

  // Input arr[] = {3, 4, 5, 1, 2}
  // Element to Search = 1
  //   1) Find out pivot point and divide the array in two
  //       sub-arrays. (pivot = 2) /*Index of 5*/
  //   2) Now call binary search for one of the two sub-arrays.
  //       (a) If element is greater than 0th element then
  //              search in left array
  //       (b) Else Search in right array
  //           (1 will go in else as 1 < 0th element(3))
  //   3) If element is found in selected sub-array then return index
  //      Else return -1.

  int a[] = {4, 5, 6, 7, 8, 9, 10, 1, 2, 3};

  // a[] of size 10
  int n = 10;

  // element to find
  int element = 5;

  int pivotIndex = -1;

  for (int i = 0; i < n-1; i++) {
    if (a[i] > a[i + 1]) {
      pivotIndex = i;
      break;
    }
  }
  if (pivotIndex == -1) {
    cout << "-1" << endl;
    return;
  }
  if (a[pivotIndex] > )
  
  return 0;
}
