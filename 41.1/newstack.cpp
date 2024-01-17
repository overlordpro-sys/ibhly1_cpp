#include "newstack.h"
#include <iostream>
#include <stdlib.h>
using std::cerr;
using std::endl;
const int SDEFAULT_SIZE = 10; // default initial stack size

template <class itemType>
apstack<itemType>::apstack()
    : myElements(linkedlist<itemType>())

// postcondition: the stack is empty
{}

template <class itemType>
apstack<itemType>::apstack(const apstack<itemType> &s)
    : myElements(new linkedlist<itemType>(*s.myElements))

// postcondition: stack is a copy of s
{}

template <class itemType>
apstack<itemType>::~apstack()
// postcondition: stack is destroyed
{}

template <class itemType>
const apstack<itemType> &
apstack<itemType>::operator=(const apstack<itemType> &rhs)
// postcondition: normal assignment via copying has been performed
{
   if (this != &rhs) {
      myElements = rhs.myElements;
   }
   return *this;
}

template <class itemType>
bool apstack<itemType>::empty() const
// postcondition: returns true if stack is empty, false otherwise
{
   return myElements.empty();
}

template <class itemType>
int apstack<itemType>::length() const
// postcondition: returns # of elements currently in stack
{
   return myElements.length;
}

template <class itemType>
void apstack<itemType>::push(const itemType &item)
// precondition: stack is [e1, e2...en] with  n >= 0
// postcondition: stack is [e1, e2, ... en, item]
{
   myElements.addLast(item);
}

#include <iostream>

template <class itemType>
void apstack<itemType>::pop()
// precondition: stack is [e1,e2,...en] with n >= 1
// postcondition: stack is [e1,e2,...e(n-1)]
{
   if (empty()) {
      std::cerr << "error, popping an empty stack" << std::endl;
      abort();
   }
   myElements.removeLast();
}

template <class itemType>
void apstack<itemType>::pop(itemType &item)
// precondition: stack is [e1,e2,...en] with n >= 1
// postcondition: stack is [e1,e2,...e(n-1)] and item == en
{
   if (empty()) {
      cerr << "error, popping an empty stack" << endl;
      abort();
   }
   item = myElements.getLast();
   myElements.removeLast();
}

template <class itemType>
const itemType &apstack<itemType>::top() const
// precondition: stack is [e1, e2, ... en] with n >= 1
// postcondition: returns en
{
   if (empty()) {
      cerr << "error, popping an empty stack" << endl;
      abort();
   }
   return myElements.getLast();
}

template <class itemType>
void apstack<itemType>::makeEmpty()
// postcondition:  stack is empty
{
   myElements.clear();
}
