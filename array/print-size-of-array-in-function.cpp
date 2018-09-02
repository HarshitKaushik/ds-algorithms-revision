// A C++ program to show that it is wrong to
// compute size of an array parameter in a function
// Reference link: https://www.geeksforgeeks.org/how-to-print-size-of-an-array-in-a-function-in-c/

#include <iostream>
using namespace std;

void findSize(int arr[])
{
  cout << sizeof(arr) << endl;
}

int main()
{
  int a[10];
  cout << sizeof(a) << " ";
  findSize(a);
  return 0;
}

// Output:
// 40 8
// Reason size of array is 4 * 10 = 40 bytes where 4 byte is size of an int
// Arrays are passed as a pointer inside a function and size of a pointer is 8 bytes
// on the compiler where this is run.