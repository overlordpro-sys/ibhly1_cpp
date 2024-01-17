#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <class itemType> struct listNode {
   itemType item;
   listNode *next;
   listNode *prev;
   listNode(itemType, listNode *, listNode *);
};

template <class itemType> using nodePtr = listNode<itemType> *;

template <class itemType> class linkedlist {
 public:
   // constructors/destructor

   linkedlist();                    // construct empty stack
   linkedlist(const linkedlist &s); // copy constructor
   ~linkedlist();                   // destructor

   // assignment

   const linkedlist &operator=(const linkedlist &rhs);

   // accessors
   itemType &getFirst() const;
   itemType &getLast() const;
   bool empty() const; // return true if empty, else false
   int length() const; // return number of elements in linkedlist

   // modifiers
   void addFirst(itemType item);
   void addLast(itemType item);

   void removeLast();
   void removeFirst();

   void clear();

 private:
   nodePtr<itemType> first;
   nodePtr<itemType> last;
};

#endif
