#include <iostream>
using namespace std;

// Given an array a[], write a function that segregates even and odd numbers.
// The functions should put all even numbers first, and then odd numbers.
// Reference links:
// https://www.geeksforgeeks.org/segregate-even-and-odd-numbers/
// https://www.geeksforgeeks.org/segregate-even-odd-set-2/
// https://www.geeksforgeeks.org/segregate-even-odd-numbers-set-3/

// Input  = {12, 34, 45, 9, 8, 90, 3}
// Output = {12, 34, 8, 90, 45, 9, 3}

// Approach 1: Use a variation of Dutch National Flag algorithm.
// Approach 2: Use modified Lomuto Quick sort partition method

/* Function to swap *a and *b */
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Approach 1
// The function to segregate the array with even numbers first and odd numbers later.
void segregateEvenOdd(int arr[], int size)
{
  /* Initialize left and right indexes */
  int left = 0, right = size - 1;
  while (left < right)
  {
    /* Increment left index while we see 0 at left */
    while (arr[left] % 2 == 0 && left < right)
      left++;
    /* Decrement right index while we see 1 at right */
    while (arr[right] % 2 == 1 && left < right)
      right--;
    if (left < right)
    {
      /* Swap arr[left] and arr[right]*/
      swap(&arr[left], &arr[right]);
      left++;
      right--;
    }
  }
}

// Approach 2
// Function to rearrange the array in given way.
void rearrangeEvenAndOdd(int arr[], int n)
{
  // variables
  int j = -1;
  // quick sort method
  for (int i = 0; i < n; i++)
  {
    // if element of array
    // is odd then swap
    if (arr[i] % 2 == 0)
    {
      // increment j by one
      j++;
      // swap the element
      swap(arr[i], arr[j]);
    }
  }
}

/* driver program to test */
int main()
{
  int arr[] = {12, 34, 45, 9, 8, 90, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  segregateEvenOdd(arr, n);
  cout << "Array after segregation " << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  // Output:
  // Array after segregation
  // 12 34 90 8 9 45 3
  int arr2[] = {12, 34, 45, 9, 8, 90, 3};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  rearrangeEvenAndOdd(arr2, n2);
  cout << "Array after segregation " << endl;
  for (int i = 0; i < n2; i++)
    cout << arr2[i] << " ";
  cout << endl;
  // Output:
  // Array after segregation
  // 12 34 90 8 9 45 3
  return 0;
}