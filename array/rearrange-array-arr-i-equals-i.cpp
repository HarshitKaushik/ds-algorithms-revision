#include <iostream>
using namespace std;

// Rearrange an array such that arr[i] = i
// Given an array of elements of length N, ranging from 1 to N. All elements
// may not be present in the array. If element is not present then there will
// be -1 present in the array. Rearrange the array such that A[i] = i and if i
// is not present, display -1 at that place.

// Reference Link: https://www.geeksforgeeks.org/rearrange-array-arri/

// Function to rearrange an array
// such that arr[i] = i.
int rearrangeArray(int array[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "i => " << i << endl;
    if (array[i] != -1 && array[i] != i)
    {
      cout << "array[i] => " << array[i] << endl;
      int x = array[i];
      cout << "x => " << x << endl;
      // check if desired place
      // is not vacated
      while (array[x] != -1 && array[x] != x)
      {
        cout << "array[x] => " << array[x] << endl;
        // store the value from
        // desired place
        int y = array[x];
        // place the x to its correct
        // position
        array[x] = x;
        // now y will become x, now
        // search the place for x
        x = y;
        cout << "xAgain => " << x << endl;
      }
      // place the x to its correct
      // position
      cout << "x => " << x << endl;
      array[x] = x;
      // check if while loop hasn't
      // set the correct value at A[i]
      if (array[i] != i)
      {
        cout << "array[i] => " << array[i] << endl;
        // if not then put -1 at
        // the vacated place
        array[i] = -1;
      }
    }
  }
}

// Driver function.
int main()
{
  int testArray[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
  int len = sizeof(testArray) / sizeof(testArray[0]);
  rearrangeArray(testArray, len);
  for (int i = 0; i < len; i++)
    cout << testArray[i] << " ";
  // Output:
  // -1 1 2 3 4 -1 6 -1 -1 9

  // Iterations
  // -1 -1 6 1 9 3 2 -1 4 -1
  // -1 -1 6 1 9 3 2 -1 4 -1
  // -1 -1 2 1 9 3 6 -1 4 -1
  // -1 1 2 -1 9 3 6 -1 4 -1
  // -1 1 2 -1 -1 3 6 -1 4 9
  // -1 1 2 3 -1 -1 6 -1 4 9
  // -1 1 2 3 -1 -1 6 -1 4 9
  // -1 1 2 3 4 -1 6 -1 -1 9
  // -1 1 2 3 4 -1 6 -1 -1 9
}