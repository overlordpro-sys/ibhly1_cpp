#include <iostream>

using namespace std;
struct listNode {
   int data;
   listNode *next;

   listNode(int, listNode *);
};

listNode::listNode(int tempData, listNode *tempNext)
    : data(tempData), next(tempNext) {
   // all values initialized in initializer list
}

typedef listNode *nodePtr;

struct listType {
   nodePtr first;
   nodePtr last;
};

void createList(listType &);
void printList(listType);
void insertNode(listType &, int);

int main() {
   listType list;

   createList(list);
   printList(list);
   return 0;
}

void createList(listType &list) {
   for (int k = 1; k <= 20; k++)
      insertNode(list, k);
}

void printList(listType list) {
   nodePtr temp = list.first;
   while (temp != nullptr) {
      cout << temp->data << "   ";
      temp = temp->next;
   }
   cout << endl;
}

void insertNode(listType &list, int value) {
   // insert a node into the list
   // if list is empty, insert node as first and last
   if (list.first == nullptr) {
      list.first = new listNode(value, nullptr);
      list.last = list.first;
   } else {
      // if list is not empty, insert node as last
      list.last->next = new listNode(value, nullptr);
      list.last = list.last->next;
   }
}
