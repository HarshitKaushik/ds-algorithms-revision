// STL based C++ program to find k-th smallest
// element.
// Reference link: https://www.geeksforgeeks.org/kth-smallestlargest-element-using-stl/
#include <iostream>
#include <set>
using namespace std;

// Return the kth smallest element in arr of size n
int kthSmallest(int arr[], int n, int k)
{
  // Insert all elements into the set
  set<int> s;
  for (int i = 0; i < n; i++)
    s.insert(arr[i]);
  // Traverse set and print k-th element
  auto it = s.begin();
  for (int i = 0; i < k - 1; i++)
    it++;
  return *it;
}

// Driver function
int main()
{
  int arr[] = {12, 3, 5, 7, 3, 19};
  int n = sizeof(arr) / sizeof(arr[0]), k = 2;
  cout << "K'th smallest element is "
       << kthSmallest(arr, n, k) << endl;
  return 0;
  // k'th smallest element is 5
}