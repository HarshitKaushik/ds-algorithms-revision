#include <iostream>
using namespace std;

// Find maximum value of Sum(i * arr[i]) with only rotations on given array allowed
// https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/

// S-sum = a[0] + a[1] + a[2] + ... + a[n-1]
// S0 = 0 * a[0] + 1 * a[1] + ... + (n-1) * a[n-1]
// S1 = 0 * a[1] + 1 * a[2] + ... + (n-1) * a[0]
// Derive a pattern from S1 - S0 for S(i+1) - S(i)

// Input : arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// Output : 330

int main()
{
  int testArray[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = 10;
  // I'll use left rotation to derive the formula
  // Calculate S-sum - sum of all elements
  int arraySum = 0;
  int initialSum = 0;
  for (int i = 0; i < size; i++) {
    arraySum += testArray[i];
    initialSum += i * testArray[i];
  }
  int maximalSum = initialSum;
  for (int i = 0; i < size - 1; i++) {
    int nextSum = initialSum + size * testArray[i] - arraySum;
    if (nextSum > maximalSum) {
      maximalSum = nextSum;
    }
    initialSum = nextSum;
  }
  cout << maximalSum << endl;
  // Computes the maximum value of i * arr[i] after any number of left rotations
  // Let's test this
  // Yeah
  // 330
  // Similarly a formula can be derived for right rotations.
  return 0;
}
