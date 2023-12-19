#include <fstream>
#include <iostream>

using namespace std;

struct listNode {
   int id, inv;
   listNode *next;

   listNode(int, int, listNode *);
};

listNode::listNode(int tempId, int tempInv, listNode *tempNext)
    : id(tempId), inv(tempInv), next(tempNext) {
   // all values initialized in initializer list
}

typedef listNode *nodePtr;

struct listType {
   nodePtr first;
   nodePtr last;

 public:
   listType() : first(nullptr), last(nullptr) {
      // all values initialized in initializer list
   }
};

void loadList(string filename, listType &);
void printList(listType);
void addFirst(listType &, int, int);
void addLast(listType &, int, int);
void reverse(listType &);
int size(const listType);
listType mergeSort(listType &);
listType merge(listType &, listType &);
void split(listType &, listType &);

int main() {
   listType list;
   string filename = "FILE20.txt";
   loadList(filename, list);
   printList(list);
   list = mergeSort(list);
   printList(list);

   reverse(list);
   printList(list);

   return 0;
}

void loadList(string filename, listType &list) {
   ifstream in(filename, ios::in);
   int id, inv;
   while (in >> id >> inv) {
      list.first = new listNode(id, inv, list.first);
   }
}

void printList(listType list) {
   cout << "\n--List--" << endl;
   nodePtr temp = list.first;
   while (temp != nullptr) {
      cout << "Id: " << temp->id << " Inv: " << temp->inv << "\n";
      temp = temp->next;
   }
   cout << "\n\n";
}

void addFirst(listType &list, int id, int inv) {
   if (list.first == nullptr) {
      list.first = new listNode(id, inv, nullptr);
      list.last = list.first;
   } else {
      list.first = new listNode(id, inv, list.first);
   }
}

void addLast(listType &list, int id, int inv) {
   if (list.first == nullptr) {
      list.first = new listNode(id, inv, nullptr);
      list.last = list.first;
   } else {
      list.last->next = new listNode(id, inv, nullptr);
      list.last = list.last->next;
   }
}

nodePtr popFirst(listType &list) {
   nodePtr temp = list.first;
   list.first = list.first->next;
   return temp;
}

int size(const listType list) {
   int count = 0;
   nodePtr temp = list.first;
   while (temp != nullptr) {
      count++;
      temp = temp->next;
   }
   return count;
}

// recursive
void reverse(listType &list) {
   listType tempList;
   nodePtr temp = list.first;
   while (temp != nullptr) {
      addFirst(tempList, temp->id, temp->inv);
      temp = temp->next;
   }
   list = tempList;
}

listType mergeSort(listType &list1) {
   if (list1.first == nullptr) {
      return list1;
   }
   if (size(list1) <= 1) {
      return list1;
   }
   listType list2;
   split(list1, list2);
   list1 = mergeSort(list1);
   list2 = mergeSort(list2);
   return merge(list1, list2);
}

// split contents of list one into both list 1 and 2 50/50
void split(listType &list1, listType &list2) {
   int count = size(list1) / 2;
   for (int i = 0; i < count; i++) {
      nodePtr temp = popFirst(list1);
      addLast(list2, temp->id, temp->inv);
   }
   listType tempList = list1;
   list1 = list2;
   list2 = tempList;
}

listType merge(listType &list1, listType &list2) {
   listType list;
   while (list1.first != nullptr && list2.first != nullptr) {
      if (list1.first->id < list2.first->id) {
         nodePtr temp = popFirst(list1);
         addLast(list, temp->id, temp->inv);
      } else {
         nodePtr temp = popFirst(list2);
         addLast(list, temp->id, temp->inv);
      }
   }
   while (list1.first != nullptr) {
      nodePtr temp = popFirst(list1);
      addLast(list, temp->id, temp->inv);
   }
   while (list2.first != nullptr) {
      nodePtr temp = popFirst(list2);
      addLast(list, temp->id, temp->inv);
   }
   return list;
}