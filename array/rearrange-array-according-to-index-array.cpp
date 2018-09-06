#include <iostream>
using namespace std;

// Reorder an array according to given index array
// Given two integer arrays of same size, “arr[]” and “index[]”, reorder
// elements in “arr[]” according to given index array. It is not allowed to
// given array arr’s length.

// Reference link: https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/

// Input:  arr[]   = [50, 40, 70, 60, 90]
// index[] = [3,  0,  4,  1,  2]
// Output: arr[]   = [40, 60, 90, 50, 70]
// index[] = [0,  1,  2,  3,   4]

// Expected time complexity O(n) and auxiliary space O(1)

// A Simple Solution is to use an auxiliary array temp[] of same size as given
// arrays. Traverse the given array and put all elements at their correct place
// in temp[] using index[]. Finally copy temp[] to arr[] and set all values of
// index[i] as i.

int main() {
  int testArray[] = {50, 40, 70, 60, 90};
  int indexArray[] = {3, 0, 4, 1, 2};
  int size = 5;
  int tempArray[size];
  for(int i = 0; i < size; i++) {
    tempArray[indexArray[i]] = testArray[i];
  }
  for(int i = 0; i < size; i++) {
    testArray[i] = tempArray[i];
    indexArray[i] = i;
  }
  cout << "Test array: " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << testArray[i] << " ";
  }
  cout << endl;
  cout << "Index array: " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << indexArray[i] << " ";
  }
  cout << endl;
  return 0;
}