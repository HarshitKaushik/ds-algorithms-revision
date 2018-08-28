#include <iostream>
using namespace std;

// Range Queries on Left and Right Circular shift on array
// Reference Link: https://www.geeksforgeeks.org/queries-left-right-circular-shift-array/
// Given an array a of n integers. There are three type of commands:
// 1 x : Right Circular Shift the array x times.
// 2 y : Left Circular Shift the array y times.
// 3 l r : Print the sum of all integers in the subarray a[l…r] (l and r inclusive)
// Given Q queries, the task is execute each query.

// Apart from brute force, an efficient approach to solve this problem
// Initially, there are no rotations and we have many queries asking for sum
// of integers present in a range od indexes.

// We can evaluate the prefix sum of all elements in the array, prefixsum[i]
// will denote the sum of all the integers upto ith index.
// Now, if we want to find sum of elements between two indexes i.e l and r, we
// compute it in constant time by just calculating
// prefixsum[r] – prefixsum[l – 1]

// We just need to track the net rotation. If the tracked number is negative,
// it means left rotation has domainated else right rotation has dominated.
// When we are tracking the net rotations, we need to do mod n. As after every
// n rotation, array will return to its original state.

// We need to observe it in such a way that every time we rotate the array,
// only its indexes are changing.
// If we need to answer any query of third type and we have l and r. We need to
// find what l and r were in the original order. We can easily find it out by
// adding the net rotations to the index and taking mod n.
// Every command can be executed in O(1) time.

// CPP Program to solve queries on Left and Right
// Circular shift on array

// Function to solve query of type 1 x.
void querytype1(int *toRotate, int times, int n)
{
  // Decreasing the absolute rotation
  (*toRotate) = ((*toRotate) - times) % n;
}

// Function to solve query of type 2 y.
void querytype2(int *toRotate, int times, int n)
{
  // Increasing the absolute rotation.
  (*toRotate) = ((*toRotate) + times) % n;
}

// Function to solve queries of type 3 l r.
void querytype3(int toRotate, int l, int r,
                int preSum[], int n)
{
  // Finding absolute l and r.
  l = (l + toRotate + n) % n;
  r = (r + toRotate + n) % n;

  // if l is before r.
  if (l <= r)
    cout << (preSum[r + 1] - preSum[l]) << endl;

  // If r is before l.
  else
    cout << (preSum[n] + preSum[r + 1] - preSum[l])
         << endl;
}

// Wrapper Function solve all queries.
void wrapper(int a[], int n)
{
  int preSum[n + 1];
  preSum[0] = 0;

  // Finding Prefix sum
  for (int i = 1; i <= n; i++)
    preSum[i] = preSum[i - 1] + a[i - 1];

  int toRotate = 0;

  // Solving each query
  querytype1(&toRotate, 3, n);
  // 3 4 5 1 2
  querytype3(toRotate, 0, 2, preSum, n);
  // 12
  querytype2(&toRotate, 1, n);
  // 4 5 1 2 3
  querytype3(toRotate, 1, 4, preSum, n);
  // 11
}

// Driver Program
int main()
{
  int a[] = {1, 2, 3, 4, 5};
  int n = sizeof(a) / sizeof(a[0]);
  wrapper(a, n);
  return 0;
}