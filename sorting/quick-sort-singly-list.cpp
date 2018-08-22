#include <iostream>
using namespace std;

// Quick sort for singly linked list
// https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
// Worst case time complexity same as for arrays - O(n^2)
// Average and best case time complexity same as for arrays - O(n log n)

// A simple node struct to be used with linked list
struct Node
{
  int value;
  Node *next;
};

// A utility function to insert a node at the beginning of linked list
void pushAtBegin(Node **headRef, int newData)
{
  Node *newNode = new Node;
  newNode->value = newData;
  newNode->next = (*headRef);
  (*headRef) = newNode;
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

// Get last element in the linked list
Node *getLastElement(Node *head)
{
  while (head && head->next)
  {
    head = head->next;
  }
  return head;
}

// Partitions the list taking the last element as the pivot
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
  Node *pivot = end;
  Node *prev = NULL, *cur = head, *tail = pivot;
  // During partition, both the head and end of the list might change
  // which is updated in the newHead and newEnd variables
  while (cur != pivot)
  {
    if (cur->value < pivot->value)
    {
      // First node that has a value less than the pivot - becomes
      // the new head
      if ((*newHead) == NULL)
        (*newHead) = cur;
      prev = cur;
      cur = cur->next;
    }
    else // If cur node is greater than pivot
    {
      // Move cur node to next of tail, and change tail
      if (prev)
        prev->next = cur->next;
      Node *temp = cur->next;
      cur->next = NULL;
      tail->next = cur;
      tail = cur;
      cur = temp;
    }
  }
  // If the pivot data is the smallest element in the current list,
  // pivot becomes the head
  if ((*newHead) == NULL)
    (*newHead) = pivot;
  // Update newEnd to the current last node
  (*newEnd) = tail;
  // Return the pivot node
  return pivot;
}

//here the sorting happens exclusive of the end node
Node *quickSortRecur(Node *head, Node *end)
{
  // base condition
  if (!head || head == end)
    return head;
  Node *newHead = NULL, *newEnd = NULL;
  // Partition the list, newHead and newEnd will be updated
  // by the partition function
  Node *pivot = partition(head, end, &newHead, &newEnd);
  // If pivot is the smallest element - no need to recur for
  // the left part.
  if (newHead != pivot) {
    // Set the node before the pivot node as NULL
    Node *temp = newHead;
    while (temp->next != pivot)
      temp = temp->next;
    temp->next = NULL;
    // Recur for the list before pivot
    newHead = quickSortRecur(newHead, temp);
    // Change next of last node of the left half to pivot
    temp = getLastElement(newHead);
    temp->next = pivot;
  }
  // Recur for the list after the pivot element
  pivot->next = quickSortRecur(pivot->next, newEnd);
  return newHead;
}

// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(Node **headRef)
{
  (*headRef) = quickSortRecur(*headRef, getLastElement(*headRef));
  return;
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
  quickSort(&testList);
  cout << "Linked List after sorting \n";
  printList(testList);
}
