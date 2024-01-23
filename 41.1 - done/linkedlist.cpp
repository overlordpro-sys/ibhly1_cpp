#include "linkedlist.h"

template <class itemType>
listNode<itemType>::listNode(itemType item, listNode<itemType> *tempPrev,
                             listNode<itemType> *tempNext)
    : item(item), prev(tempPrev), next(tempNext) {
   // all values initialized in initializer list
}

template <class itemType> linkedlist<itemType>::linkedlist() {
   first = nullptr;
   last = nullptr;
}

template <class itemType>
linkedlist<itemType>::linkedlist(const linkedlist<itemType> &s) {
   first = nullptr;
   last = nullptr;
   nodePtr<itemType> temp = s.first;
   while (temp != nullptr) {
      addLast(temp->item);
      temp = temp->next;
   }
}

template <class itemType> linkedlist<itemType>::~linkedlist() {
   nodePtr<itemType> temp = first;
   while (temp != nullptr) {
      first = first->next;
      delete temp;
      temp = first;
   }
   last = nullptr;
}

template <class itemType>
const linkedlist<itemType> &
linkedlist<itemType>::operator=(const linkedlist &rhs) {
   if (this != &rhs) {
      clear();
      nodePtr<itemType> temp = rhs.first;
      while (temp != nullptr) {
         addLast(temp->item);
         temp = temp->next;
      }
   }
   return *this;
}

template <class itemType> itemType &linkedlist<itemType>::getFirst() const {
   return first->item;
}

template <class itemType> itemType &linkedlist<itemType>::getLast() const {
   return last->item;
}

template <class itemType> bool linkedlist<itemType>::empty() const {
   return first == nullptr;
}

template <class itemType> int linkedlist<itemType>::length() const {
   if (empty()) {
      return 0;
   }
   int count = 0;
   nodePtr<itemType> temp = first;
   while (temp != nullptr) {
      count++;
      temp = temp->next;
   }
   return count;
}

template <class itemType> void linkedlist<itemType>::addFirst(itemType item) {
   if (first == nullptr) {
      first = new listNode<itemType>(item, nullptr, nullptr);
      last = first;
   } else {
      first->prev = new listNode<itemType>(item, nullptr, first);
      first = first->prev;
   }
}

template <class itemType> void linkedlist<itemType>::addLast(itemType item) {
   if (first == nullptr) {
      addFirst(item);
   } else {
      last->next = new listNode<itemType>(item, last, nullptr);
      last = last->next;
   }
}

template <class itemType> void linkedlist<itemType>::removeLast() {
   if (first == nullptr) {
      return;
   } else if (first == last) {
      delete first;
      first = nullptr;
      last = nullptr;
   } else {
      nodePtr<itemType> temp = last;
      last = last->prev;
      last->next = nullptr;
      delete temp;
   }
}

template <class itemType> void linkedlist<itemType>::removeFirst() {
   if (first == nullptr) {
      return;
   } else if (first == last) {
      delete first;
      first = nullptr;
      last = nullptr;
   } else {
      nodePtr<itemType> temp = first;
      first = first->next;
      first->prev = nullptr;
      delete temp;
   }
}

template <class itemType> void linkedlist<itemType>::clear() {
   nodePtr<itemType> temp = first;
   while (temp != nullptr) {
      first = first->next;
      delete temp;
      temp = first;
   }
   last = nullptr;
}
