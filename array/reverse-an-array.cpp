#include <iostream>
using namespace std;

// A program to reverse an array or string - same login for layman question
// Start from begin and end and swap arr[begin] and arr[end]
// begin = begin + 1 and end = end - 1 until begin <= mid
// where mid = (begin + end) / 2
// Reference Link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
// Both the iterative and the recursive solutions solve the problem in O(n)

// Reverse array by iteration
void reverseArrayIterative(int array[], int size) {
  int begin = 0;
  int end = size - 1;
  int mid = (begin + end) / 2;
  while (begin <= mid) {
    int temp = array[begin];
    array[begin] = array[end];
    array[end] = temp;
    begin++;
    end--;
  }
}

// Reverse array by recursion
void reverseArrayRecursive(int array[], int begin, int end) {
  if (begin < end) {
    int temp = array[begin];
    array[begin] = array[end];
    array[end] = temp;
    reverseArrayRecursive(array, begin + 1, end - 1);
  }
}

// Reverse string by iteration
void reverseStringIterative(char string[], int size)
{
  int begin = 0;
  int end = size - 1;
  int mid = (begin + end) / 2;
  while (begin <= mid)
  {
    char temp = string[begin];
    string[begin] = string[end];
    string[end] = temp;
    begin++;
    end--;
  }
}

// Reverse string by recursion
void reverseStringRecursive(char string[], int begin, int end)
{
  if (begin < end)
  {
    char temp = string[begin];
    string[begin] = string[end];
    string[end] = temp;
    reverseStringRecursive(string, begin + 1, end - 1);
  }
}

// Driver program
int main() {
  int testArray[] = {3, 4, 5, 6, 7, 2};
  int testArraySize = 6;
  reverseArrayIterative(testArray, testArraySize);
  for (int i = 0; i < testArraySize; i++) {
    cout << testArray[i];
  }
  cout << endl;
  int testArray2[] = {3, 4, 5, 6, 7, 2};
  int testArray2Size = 6;
  reverseArrayRecursive(testArray2, 0, testArray2Size - 1);
  for (int i = 0; i < testArray2Size; i++)
  {
    cout << testArray2[i];
  }
  cout << endl;
  char testString[] = "harshit";
  int testStringLength = 7;
  reverseStringIterative(testString, testStringLength);
  for (int i = 0; i < testStringLength; i++)
  {
    cout << testString[i];
  }
  cout << endl;
  char testString2[] = "harshit";
  int testString2Length = 7;
  reverseStringRecursive(testString2, 0, testString2Length - 1);
  for (int i = 0; i < testString2Length; i++)
  {
    cout << testString2[i];
  }
  cout << endl;
  return 0;

  // Output:
  // 276543
  // 276543
  // tihsrah
  // tihsrah
}