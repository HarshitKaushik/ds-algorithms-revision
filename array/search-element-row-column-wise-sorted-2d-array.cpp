#include <iostream>
using namespace std;

// Search in a row wise and column wise sorted matrix
// Given a n x n matrix and a number x, find position of x in the matrix if it
// is present in it. Else print “Not Found”. In the given matrix, every row and
// column is sorted in increasing order. The designed algorithm should have
// linear time complexity.

// Reference link: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

// Searches the element x in mat[][]. If the
// element is found, then prints its position
// and returns true, otherwise prints "not found"
// and returns false
bool search(int *mat, int n, int x)
{
  //set indexes for top right element
  int i = 0, j = n - 1;
  while (i < n && j >= 0)
  {
    if (*(mat + i * n + j) == x)
    {
      cout << "Element Found at array["
           << i << "][" << j << "];\n";
      return true;
    }
    if (*(mat + i * n + j) > x)
      j--;
    else
      // if mat[i][j] < x
      i++;
  }
  cout << "Element not found";
  return false;
}

// Driver code
int main()
{
  int mat[4][4] = {{10, 20, 30, 40},
                   {15, 25, 35, 45},
                   {27, 29, 37, 48},
                   {32, 33, 39, 50}};
  search(&mat[0][0], 4, 29);
  // Output
  // Element Found at array[2][1];
  return 0;
}