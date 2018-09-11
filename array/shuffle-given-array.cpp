#include <iostream>
using namespace std;

// Shuffle a given array

// Given an array, write a program to generate a random permutation of array
// elements. This question is also asked as “shuffle a deck of cards” or
// “randomize a given array”. Here shuffle means that every permutation of
// array element should equally likely.

// Reference link: https://www.geeksforgeeks.org/shuffle-a-given-array/

// Fisher–Yates shuffle Algorithm works in O(n) time complexity. The assumption
// here is, we are given a function rand() that generates a random number in O(1)
// time.

// A utility function to swap to integers
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// A utility function to print an array
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// A function to generate a random permutation of arr[]
void randomize(int arr[], int n)
{
  // Use a different seed value so that we don't get same
  // result each time we run this program
  srand(time(NULL));
  // Start from the last element and swap one by one. We don't
  // need to run for the first element that's why i > 0
  for (int i = n - 1; i > 0; i--)
  {
    // Pick a random index from 0 to i
    int j = rand() % (i + 1);
    // Swap arr[i] with the element at random index
    swap(&arr[i], &arr[j]);
  }
}

// Driver program to test above function.
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  randomize(arr, n);
  printArray(arr, n);
  return 0;
  // Output:
  // 8 5 6 7 4 1 3 2
}