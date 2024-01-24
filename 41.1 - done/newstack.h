#ifndef _NEWSTACK_H
#define _NEWSTACK_H

#include "linkedlist.h" // used for stack implementation

template <class itemType> class newstack {
 public:
   // constructors/destructor

   newstack();                 // construct empty stack
   newstack(const newstack &s); // copy constructor
   ~newstack();                // destructor

   // assignment

   const newstack &operator=(const newstack &rhs);

   // accessors

   const itemType &top() const; // return top element (NO pop)
   bool empty() const;          // return true if empty, else false
   int length() const;          // return number of elements in stack

   // modifiers

   void push(const itemType &item); // push item onto top of stack
   void pop();                      // pop top element
   void pop(itemType &item);        // combines pop and top
   void makeEmpty();                // make stack empty (no elements)

 private:
   linkedlist<itemType> myElements; // storage for stack
};

// **********************************************************************
//
// Specifications for stack functions
//
// Any violation of a function's precondition will result in an error message
// followed by a call to abort.
//
//
// constructors/destructor
//
//  newstack( )
//    postcondition: the stack is empty
//
//  newstack( const newstack & s )
//    postcondition: stack is a copy of s
//
//  newstackk( )
//    postcondition: stack is destroyed
//
// assignment
//
//  const newstack & operator = ( const newstack & rhs )
//    postcondition: normal assignment via copying has been performed
//
// accessors
//
//  const itemType & top( ) const
//    precondition: stack is [e1, e2, ... en] with n >= 1
//    postcondition: returns en
//
//  bool isEmpty( ) const
//     postcondition: returns true if stack is empty, false otherwise
//
//  int length( ) const
//     postcondition: returns # of elements currently in stack
//
// modifiers
//
//  void push( const itemType & item )
//     precondition: stack is [e1, e2...en] with  n >= 0
//     postcondition: stack is [e1, e2, ... en, item]
//
//  void pop( )
//     precondition: stack is [e1, e2, ... en] with n >= 1
//     postcondition: stack is [e1, e2, ... e(n-1)]
//
//
//  void pop(itemType & item )
//     precondition: stack is [e1,e2,...en] with n >= 1
//     postcondition: stack is [e1,e2,...e(n-1)] and item == en
//
//  void makeEmpty( )
//     postcondition:  stack is empty
//
//  Examples of variable definition
//
//    newstack<int> istack;                    // creates empty stack of integers
//    newstack<double> dstack;                 // creates empty stack of doubles
//

#endif
