#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Arrange given numbers to form the biggest number | Set 1

// Reference Link: https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
// http://www.cplusplus.com/reference/algorithm/sort/
// Given an array of numbers, arrange them in a way that yields the largest
// value. For example, if the given numbers are {54, 546, 548, 60}, the
// arrangement 6054854654 gives the largest value. And if the given numbers are
// {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.

// The idea is to use any comparison based sorting algorithm. In the used
// sorting algorithm, instead of using the default comparison, write a
// comparison function myCompare() and use it to sort numbers. Given two
// numbers X and Y, how should myCompare() decide which number to put first –
// we compare two numbers XY (Y appended at the end of X) and YX (X appended at
// the end of Y). If XY is larger, then X should come before Y in output, else
// Y should come before. For example, let X and Y be 542 and 60. To compare X
// and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put
// Y first.

// A comparison function which is used by sort() in printLargest()
int myCompare(string x, string y)
{
  // first append Y at the end of X
  string xy = x.append(y);
  // then append X at the end of Y
  string yx = y.append(x);
  // Now see which of the two formed numbers is greater
  return xy.compare(yx) > 0 ? 1 : 0;
}

// The main function that prints the arrangement with the largest value.
// The function accepts a vector of strings
void printLargest(vector<string> arr)
{
  // Sort the numbers using library sort funtion. The function uses
  // our comparison function myCompare() to compare two strings.
  // See http://www.cplusplus.com/reference/algorithm/sort/ for details
  sort(arr.begin(), arr.end(), myCompare);
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i];
  cout << endl;
}

// driver program to test above functions
int main()
{
  vector<string> arr;
  //output should be 6054854654
  arr.push_back("54");
  arr.push_back("546");
  arr.push_back("548");
  arr.push_back("60");
  printLargest(arr);

  vector<string> arr2;
  // output should be 777776
  arr2.push_back("7");
  arr2.push_back("776");
  arr2.push_back("7");
  arr2.push_back("7");
  printLargest(arr2);

  vector<string> arr3;
  //output should be 998764543431
  arr3.push_back("1");
  arr3.push_back("34");
  arr3.push_back("3");
  arr3.push_back("98");
  arr3.push_back("9");
  arr3.push_back("76");
  arr3.push_back("45");
  arr3.push_back("4");
  printLargest(arr3);

  return 0;
}