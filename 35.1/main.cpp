#include <fstream>
#include <iostream>

using namespace std;

struct listNode {
   int id, inv;
   listNode *next;
   listNode *prev;
   listNode(int, int, listNode *, listNode *);
};

listNode::listNode(int tempId, int tempInv, listNode *tempPrev,
                   listNode *tempNext)
    : id(tempId), inv(tempInv), prev(tempPrev), next(tempNext) {
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
void printListReverse(listType);
void addFirst(listType &, int, int);
void addLast(listType &, int, int);
void insertInOrder(listType &, int, int);
nodePtr search(const listType, int);
void removeNode(listType &, int);
void clearList(listType &);
int countNodes(const listType);
void reverse(const listType);
void printBackwardHelper(nodePtr temp);

int main() {
   listType list;
   string filename = "file10.txt";
   loadList(filename, list);
   printList(list);
   printListReverse(list);

   removeNode(list, 19967);
   removeNode(list, 184);
   removeNode(list, 8303);
   removeNode(list, 15814);
   printList(list);
   return 0;
}

void loadList(string filename, listType &list) {
   ifstream in(filename, ios::in);
   int id, inv;
   while (in >> id >> inv) {
      insertInOrder(list, id, inv);
   }
}

void printList(listType list) {
   int count = 1;
   cout << "\n--List--" << endl;
   nodePtr temp = list.first;
   while (temp != nullptr) {
      cout << count << ". Id: " << temp->id << " Inv: " << temp->inv << "\n";
      temp = temp->next;
      count++;
   }
   cout << "\n\n";
}

void printListReverse(listType list) {
   int count = 1;
   cout << "\n--List--" << endl;
   nodePtr temp = list.last;
   while (temp != nullptr) {
      cout << count << ". Id: " << temp->id << " Inv: " << temp->inv << "\n";
      temp = temp->prev;
      count++;
   }
   cout << "\n\n";
}

void addFirst(listType &list, int id, int inv) {
   if (list.first == nullptr) {
      list.first = new listNode(id, inv, nullptr, nullptr);
      list.last = list.first;
   } else {
      list.first->prev = new listNode(id, inv, nullptr, list.first);
      list.first = list.first->prev;
   }
}

void addLast(listType &list, int id, int inv) {
   if (list.first == nullptr) {
      addFirst(list, id, inv);
   } else {
      list.last->next = new listNode(id, inv, list.last, nullptr);
      list.last = list.last->next;
   }
}

void insertInOrder(listType &list, int id, int inv) {
   // insert a node into the list
   // if list is empty, insert node as first and last
   if (list.first == nullptr) {
      addFirst(list, id, inv);
   } else if (id < list.first->id) {
      addFirst(list, id, inv);
   } else if (id > list.last->id) {
      addLast(list, id, inv);
   } else {
      nodePtr front = list.first;
      nodePtr back = nullptr;
      while (front != nullptr && id > front->id) {
         back = front;
         front = front->next;
      }
      back->next = new listNode(id, inv, back, front);
      front->prev = back->next;
   }
}

nodePtr search(listType list, int id) {
   nodePtr temp = list.first;
   while (temp != nullptr) {
      if (temp->id == id) {
         return temp;
      }
      temp = temp->next;
   }
   return nullptr;
}

void removeNode(listType &list, int id) {
   nodePtr front = list.first;
   nodePtr back = nullptr;
   while (front != nullptr && front->id != id) {
      back = front;
      front = front->next;
   }
   if (front == nullptr) {
      cout << id << " not found" << endl;
      return;
   }
   if (front == list.first) {
      list.first = list.first->next;
      list.first->prev = nullptr;
   } else if (front == list.last) {
      list.last = list.last->prev;
      list.last->next = nullptr;
   } else {
      back->next = front->next;
      back->next->prev = back;
   }
   cout << "Deleted " << front->id << " " << front->inv << endl;
   delete front;
}

void clearList(listType &list) {
   nodePtr temp = list.first;
   while (temp != nullptr) {
      list.first = list.first->next;
      delete temp;
      temp = list.first;
   }
   list.last = nullptr;
}

int countNodes(const listType list) {
   int count = 0;
   nodePtr temp = list.first;
   while (temp != nullptr) {
      count++;
      temp = temp->next;
   }
   return count;
}

// recursive
void reverse(const listType list) { printBackwardHelper(list.first); }

void printBackwardHelper(nodePtr temp) {
   if (temp == nullptr) {
      return;
   }
   printBackwardHelper(temp->next);
   cout << "Id: " << temp->id << " Inv: " << temp->inv << "\n";
}