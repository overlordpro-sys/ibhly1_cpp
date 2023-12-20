#include <fstream>
#include <iostream>

using namespace std;

struct treeNode {
   int id, inv;
   treeNode *left, *right;
   treeNode(int, int, treeNode *, treeNode *);
};

treeNode::treeNode(int tempId, int tempInv, treeNode *tempLeft,
                   treeNode *tempRight)
    : id(tempId), inv(tempInv), left(tempLeft), right(tempRight) {}

typedef treeNode *treePtr;

struct binaryTree {
   treePtr root;

 public:
   binaryTree() : root(nullptr) {}
};

void loadTree(string filename, binaryTree &tree);
void printInorder(binaryTree tree);
void printInorderHelper(treePtr tree);
void printPreorder(binaryTree tree);
void printPreorderHelper(treePtr tree);
void printPostorder(binaryTree tree);
void printPostorderHelper(treePtr tree);
void insertNode(binaryTree &, int, int);
void insertNodeHelper(treePtr &, int, int);
bool deleteNode(binaryTree &, int);
void deleteTargetNode(treePtr &);
bool deleteNodeHelper(treePtr &, int);
void testDelete(binaryTree &);
int countNodes(binaryTree);
int countNodesHelper(treePtr);
treePtr search(binaryTree, int);
treePtr searchHelper(treePtr, int);

int main() {
   binaryTree tree;
   string filename = "FILE20.txt";
   // Spawn menu with these options (1)	Read a file from disk, build the binary
   // tree
   // (2) Print the tree in order(3) Search the tree(4) Delete from the tree(5)
   //     Count the nodes in the tree
   int choice = 0;
   while (choice != 6) {
      cout << "\n1. Fill the tree from a file\n"
           << "2. Print the tree in order\n"
           << "3. Search the tree\n"
           << "4. Delete from the tree\n"
           << "5. Count the nodes in the tree\n"
           << "6. Exit\n"
           << "Enter choice: ";
      cin >> choice;
      switch (choice) {
      case 1:
         loadTree(filename, tree);
         break;
      case 2:
         printInorder(tree);
         break;
      case 3:
         int searchId;
         cout << "Enter id to search: ";
         cin >> searchId;
         treePtr result;
         result = search(tree, searchId);
         if (result == nullptr) {
            cout << "Not found\n";
         } else {
            cout << "Found - Id: " << result->id << " Inv: " << result->inv
                 << "\n";
         }
         break;
      case 4:
         testDelete(tree);
         break;
      case 5:
         cout << "Number of nodes: " << countNodes(tree) << "\n";
         break;
      case 6:
         break;
      default:
         cout << "Invalid choice\n";
      }
   }
   return 0;
}

void loadTree(string filename, binaryTree &tree) {
   ifstream in(filename, ios::in);
   int id, inv;
   while (in >> id >> inv) {
      insertNode(tree, id, inv);
   }
}

void insertNode(binaryTree &tree, int id, int inv) {
   insertNodeHelper(tree.root, id, inv);
}

void insertNodeHelper(treePtr &root, int id, int inv) {
   if (root == nullptr) {
      root = new treeNode(id, inv, nullptr, nullptr);
   } else if (id < root->id) {
      insertNodeHelper(root->left, id, inv);
   } else {
      insertNodeHelper(root->right, id, inv);
   }
}

void printInorder(binaryTree tree) {
   cout << "\n--Inorder--\n";
   printInorderHelper(tree.root);
}

void printInorderHelper(treePtr root) {
   if (root != nullptr) {
      printInorderHelper(root->left);
      cout << "Id: " << root->id << " Inv: " << root->inv << "\n";
      printInorderHelper(root->right);
   }
}

void printPreorderHelper(treePtr root) {
   if (root != nullptr) {
      cout << "Id: " << root->id << " Inv: " << root->inv << "\n";
      printPreorderHelper(root->left);
      printPreorderHelper(root->right);
   }
}

void printPostorder(binaryTree tree) { printPostorderHelper(tree.root); }

void printPostorderHelper(treePtr root) {
   if (root != nullptr) {
      printPostorderHelper(root->left);
      printPostorderHelper(root->right);
      cout << "Id: " << root->id << " Inv: " << root->inv << "\n";
   }
}

void testDelete(binaryTree &tree) {
   int idToDelete;
   bool success;

   cout << "Testing delete algorithm" << endl << endl;
   cout << "Enter Id value to delete (-1 to quit) ---> ";
   cin >> idToDelete;
   while (idToDelete >= 0) {
      success = deleteNode(tree, idToDelete);
      cout << "Id # " << idToDelete;
      if (!success)
         cout << "     No such part in stock" << endl;
      else
         cout << "     Id #" << idToDelete << " was deleted" << endl;
      cout << endl << "Enter Id value to delete (-1 to quit) ---> ";
      cin >> idToDelete;
   }
}

bool deleteNode(binaryTree &tree, int id) {
   return deleteNodeHelper(tree.root, id);
}

bool deleteNodeHelper(treePtr &node, int id) {
   if (node == nullptr)
      return false;
   if (node->id == id) {
      deleteTargetNode(node);
      return true;
   } else if (id < node->id) {
      return deleteNodeHelper(node->left, id);
   } else {
      return deleteNodeHelper(node->right, id);
   }
}

void deleteTargetNode(treePtr &target) {
   treePtr temp = target;
   if (target->left == nullptr) {
      target = target->right;
      delete temp;
   } else if (target->right == nullptr) {
      target = target->left;
      delete temp;
   } else if (target->right->left == nullptr) {
      target->id = target->right->id;
      target->inv = target->right->inv;
      target->right = target->right->right;
   } else {
      treePtr marker = target->right;
      while (marker->left->left != nullptr) {
         marker = marker->left;
      }
      target->id = marker->left->id;
      target->inv = marker->left->inv;
      treePtr temp = marker->left;
      marker->left = marker->left->right;
      delete temp;
   }
}

int countNodes(binaryTree tree) { return countNodesHelper(tree.root); }

int countNodesHelper(treePtr root) {
   if (root == nullptr) {
      return 0;
   } else {
      return countNodesHelper(root->left) + countNodesHelper(root->right) + 1;
   }
}

treePtr search(binaryTree tree, int id) { return searchHelper(tree.root, id); }

treePtr searchHelper(treePtr root, int id) {
   if (root == nullptr) {
      return nullptr;
   } else if (root->id == id) {
      return root;
   } else if (id < root->id) {
      return searchHelper(root->left, id);
   } else {
      return searchHelper(root->right, id);
   }
}
