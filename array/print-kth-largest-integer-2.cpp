#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

// k largest (or smallest) elements in an array
// program for printing k largest elements in an array. Elements in array can
// be in any order
// Reference link: https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

// Method to swap the integer values
void swapValues(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

// Approach 1:
// Modified Bubble Sort
// Runs the inner loop at most k times and prints k largest numbers
void modifiedBubbleSort(int testArray[], int size, int k) {
  for (int i = 0; i < size - 1; i++)
  {
    bool swap = false;
    for (int j = 0; j < size - 1 - i && i != k; j++)
    {
      if (testArray[j] > testArray[j + 1])
      {
        swapValues(&testArray[j], &testArray[j + 1]);
        swap = true;
      }
    }
    if (!swap)
    {
      // Already sorted array
      // break
    }
  }
  cout << "Kth largest elements: ";
  for(int i = 0; i < k; i++) {
    cout << testArray[size - 1 - i] << " ";
  }
  cout << endl;
}

// Driver program
int main() {
  int testArray1[] = {1, 5, 6, 7, 8, 28, 2, 5};
  int size1 = 8;
  int k = 3;
  modifiedBubbleSort(testArray1, size1, k);
  return 0;
}