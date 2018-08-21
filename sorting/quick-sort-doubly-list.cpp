#include <iostream>
using namespace std;

// Quick sort for doubly linked list
// https://www.geeksforgeeks.org/quicksort-for-linked-list/
// Worst case time complexity same as for arrays - O(n^2)
// Average and best case time complexity same as for arrays - O(n log n)

// A simple node struct to be used with linked list
struct Node {
  int value;
  Node *previous;
  Node *next;
};

// Method to swap the integer values
void swapValues(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

// Get last element in the linked list
Node * getLastElement(Node *head) {
  while (head && head->next) {
    head = head->next;
  }
  return head;
}

// Can we use same algorithm for Linked List?

// The idea is simple, we first find out pointer to last node. Once we have pointer to last node,
// we can recursively sort the linked list using pointers to first and last nodes of linked list, similar to the
//  above recursive function where we pass indexes of first and last array elements. The partition function for
// linked list is also similar to partition for arrays. Instead of returning index of the pivot element, it returns pointer
//  to the pivot element.

// Partition function for quick soting doubly linked list
Node * partition(Node *low, Node *high) {
  // set pivot as last element
  int x = high->value;

  // similar to i = l-1 for array implementation
  Node *i = low->previous;

  // Similar to "for (int j = l; j <= h- 1; j++)"
  for (Node *j = low; j != high; j = j->next)
  {
    if (j->value <= x)
    {
      // Similar to i++ for array
      i = (i == NULL) ? low : i->next;

      swapValues(&(i->value), &(j->value));
    }
  }
  // Swapping i+1 value with pivot element
  i = (i == NULL) ? low : i->next;
  swapValues(&(i->value), &(high->value));
  return i;
}

// Quick sort function for doubly linked list
void quickSort(Node *low, Node *high)
{
  if (high != NULL && low != high && low != high->next)
  {
    Node *pivot = partition(low, high);
    quickSort(low, pivot->previous);
    quickSort(pivot->next, high);
  }
}

// A utility function to print contents of the list
void printList(Node *head)
{
  while (head)
  {
    cout << head->value << "  ";
    head = head->next;
  }
  cout << endl;
}

// Function to insert a node at the beginning of the Doubly Linked List
void pushAtBegin(Node **head_ref, int new_data)
{
  Node *newNode = new Node;
  newNode->value = new_data;
  newNode->previous = NULL;
  newNode->next = (*head_ref);
  if ((*head_ref) != NULL)
    (*head_ref)->previous = newNode;
  // Move head reference to the new pointer
  (*head_ref) = newNode;
}

int main()
{
  // Testing the quicksort
  Node *testList;
  testList = NULL;
  pushAtBegin(&testList, 3);
  pushAtBegin(&testList, 7);
  pushAtBegin(&testList, 2);
  pushAtBegin(&testList, 5);
  pushAtBegin(&testList, 8);
  pushAtBegin(&testList, 1);
  pushAtBegin(&testList, 4);
  cout << "Linked List before sorting \n";
  printList(testList);
  Node *lastNode = getLastElement(testList);
  quickSort(testList, lastNode);
  cout << "Linked List after sorting \n";
  printList(testList);
}
