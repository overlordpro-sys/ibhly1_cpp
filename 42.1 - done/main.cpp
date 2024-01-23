#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

struct treeNode {
   char letter;
   treeNode *left, *right;
   treeNode(char, treeNode *, treeNode *);
};

treeNode::treeNode(char tempLetter, treeNode *tempLeft, treeNode *tempRight)
    : letter(tempLetter), left(tempLeft), right(tempRight) {}

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
void insertNode(binaryTree &, char);
void insertNodeHelper(treePtr &, char);
void printLevel(binaryTree);
// bool deleteNode(binaryTree &, int);
// void deleteTargetNode(treePtr &);
// bool deleteNodeHelper(treePtr &, int);
// void testDelete(binaryTree &);
int countNodes(binaryTree);
int countNodesHelper(treePtr);
// treePtr search(binaryTree, int);
// treePtr searchHelper(treePtr, int);
int width(binaryTree);
int widthHelper(treePtr);
int height(binaryTree);
int height(treePtr);
void clearTree(binaryTree &);
void clearTreeHelper(treePtr &);
int countLeaves(binaryTree);
int countLeavesHelper(treePtr);

int main() {
   binaryTree tree;
   string filename = "FILEA.TXT";

   char choice;
   while (choice != 'q') {
      cout << "\n1. Fill the tree from a file\n"
           << "2. Preorder output\n"
           << "3. Inorder output\n"
           << "4. Postorder output\n"
           << "5. Count the nodes in the tree\n"
           << "6. Count the leaves in the tree\n"
           << "7. Find the height of the tree\n"
           << "8. Find the width of the tree\n"
           << "9. Clear the tree\n"
           << "a. Print level\n"
           << "q. Quit\n"
           << "Enter choice: ";
      cin >> choice;
      switch (choice) {
      case '1':
         loadTree(filename, tree);
         break;
      case '2':
         printPreorder(tree);
         break;
      case '3':
         printInorder(tree);
         break;
      case '4':
         printPostorder(tree);
         break;
      case '5':
         cout << "Number of nodes: " << countNodes(tree) << "\n";
         break;
      case '6':
         cout << "Number of leaves: " << countLeaves(tree) << "\n";
         break;
      case '7':
         cout << "Height: " << height(tree) << "\n";
         break;
      case '8':
         cout << "Width: " << width(tree) << "\n";
         break;
      case '9':
         clearTree(tree);
         cout << "Tree cleared\n";
         break;
      case 'a':
         printLevel(tree);
         break;
      case 'q':
         break;
      default:
         cout << "Invalid choice\n";
      }
   }
   return 0;
}

void loadTree(string filename, binaryTree &tree) {
   ifstream in(filename, ios::in);
   char letter;
   while (in >> letter) {
      insertNode(tree, letter);
   }
}

void insertNode(binaryTree &tree, char letter) {
   insertNodeHelper(tree.root, letter);
}

void insertNodeHelper(treePtr &root, char letter) {
   if (root == nullptr) {
      root = new treeNode(letter, nullptr, nullptr);
   } else if (letter < root->letter) {
      insertNodeHelper(root->left, letter);
   } else {
      insertNodeHelper(root->right, letter);
   }
}

void printInorder(binaryTree tree) {
   cout << "\n--Inorder--\n";
   printInorderHelper(tree.root);
}

void printInorderHelper(treePtr root) {
   if (root != nullptr) {
      printInorderHelper(root->left);
      cout << root->letter << "\n";
      printInorderHelper(root->right);
   }
}

void printPreorder(binaryTree tree) {
   cout << "\n--Preorder--\n";
   printPreorderHelper(tree.root);
}

void printPreorderHelper(treePtr root) {
   if (root != nullptr) {
      cout << root->letter << "\n";
      printPreorderHelper(root->left);
      printPreorderHelper(root->right);
   }
}

void printPostorder(binaryTree tree) {
   cout << "\n--Postorder--\n";
   printPostorderHelper(tree.root);
}

void printPostorderHelper(treePtr root) {
   if (root != nullptr) {
      printPostorderHelper(root->left);
      printPostorderHelper(root->right);
      cout << root->letter << "\n";
   }
}

void printLevel(binaryTree tree) {
   queue<treePtr> queue;
   if (tree.root == nullptr) {
      return;
   }
   queue.push(tree.root);
   do {
      treePtr temp = queue.front();
      cout << temp->letter << " ";
      if (temp->left != nullptr) {
         queue.push(temp->left);
      }
      if (temp->right != nullptr) {
         queue.push(temp->right);
      }
      queue.pop();
   } while (!queue.empty());
   cout << "\n";
}

// void testDelete(binaryTree &tree) {
//    int idToDelete;
//    bool success;

//    cout << "Testing delete algorithm" << endl << endl;
//    cout << "Enter Id value to delete (-1 to quit) ---> ";
//    cin >> idToDelete;
//    while (idToDelete >= 0) {
//       success = deleteNode(tree, idToDelete);
//       cout << "Id # " << idToDelete;
//       if (!success)
//          cout << "     No such part in stock" << endl;
//       else
//          cout << "     Id #" << idToDelete << " was deleted" << endl;
//       cout << endl << "Enter Id value to delete (-1 to quit) ---> ";
//       cin >> idToDelete;
//    }
// }

// bool deleteNode(binaryTree &tree, int id) {
//    return deleteNodeHelper(tree.root, id);
// }

// bool deleteNodeHelper(treePtr &node, int id) {
//    if (node == nullptr)
//       return false;
//    if (node->id == id) {
//       deleteTargetNode(node);
//       return true;
//    } else if (id < node->id) {
//       return deleteNodeHelper(node->left, id);
//    } else {
//       return deleteNodeHelper(node->right, id);
//    }
// }

// void deleteTargetNode(treePtr &target) {
//    treePtr temp = target;
//    if (target->left == nullptr) {
//       target = target->right;
//       delete temp;
//    } else if (target->right == nullptr) {
//       target = target->left;
//       delete temp;
//    } else if (target->right->left == nullptr) {
//       target->id = target->right->id;
//       target->inv = target->right->inv;
//       target->right = target->right->right;
//    } else {
//       treePtr marker = target->right;
//       while (marker->left->left != nullptr) {
//          marker = marker->left;
//       }
//       target->id = marker->left->id;
//       target->inv = marker->left->inv;
//       treePtr temp = marker->left;
//       marker->left = marker->left->right;
//       delete temp;
//    }
// }

int countNodes(binaryTree tree) { return countNodesHelper(tree.root); }

int countNodesHelper(treePtr root) {
   if (root == nullptr) {
      return 0;
   } else {
      return countNodesHelper(root->left) + countNodesHelper(root->right) + 1;
   }
}

// treePtr search(binaryTree tree, int id) { return searchHelper(tree.root, id);
// }

// treePtr searchHelper(treePtr root, int id) {
//    if (root == nullptr) {
//       return nullptr;
//    } else if (root->id == id) {
//       return root;
//    } else if (id < root->id) {
//       return searchHelper(root->left, id);
//    } else {
//       return searchHelper(root->right, id);
//    }
// }

int width(binaryTree tree) {
   if (tree.root == nullptr) {
      return 0;
   }
   return widthHelper(tree.root);
}

int widthHelper(treePtr root) {
   if (root == nullptr) {
      return 0;
   }
   int width = 1;
   if (root->left != nullptr) {
      width += height(root->left);
   }
   if (root->right != nullptr) {
      width += height(root->right);
   }
   return max(width, max(widthHelper(root->left), widthHelper(root->right)));
}

int height(binaryTree tree) { return height(tree.root); }

int height(treePtr node) {
   if (node == nullptr) {
      return 0;
   }
   return max(height(node->left), height(node->right)) + 1;
}

void clearTree(binaryTree &tree) {
   clearTreeHelper(tree.root);
   tree.root = nullptr;
}

void clearTreeHelper(treePtr &root) {
   if (root == nullptr) {
      return;
   }
   clearTreeHelper(root->left);
   clearTreeHelper(root->right);
   delete root;
}

int countLeaves(binaryTree tree) {
   if (tree.root == nullptr) {
      return 0;
   }
   return countLeavesHelper(tree.root);
}

int countLeavesHelper(treePtr root) {
   if (root == nullptr) {
      return 0;
   }
   if (root->left == nullptr && root->right == nullptr) {
      return 1;
   }
   return countLeavesHelper(root->left) + countLeavesHelper(root->right);
}