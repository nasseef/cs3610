/**
 *   @file: bin-trees.cc
 * @author: Nasseef Abukamail
 *   @date: September 20, 2022
 *  @brief: Add Description
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

struct BSTNode {
    BSTNode(int newData, BSTNode *leftptr = nullptr,
            BSTNode *rightptr = nullptr) {
        data = newData;
        left = leftptr;
        right = rightptr;
    }
    int data;
    BSTNode *left;
    BSTNode *right;
};

class BST {
   public:
    BST(BSTNode *newRoot = nullptr) { root = newRoot; }
    void print() { printDepth(root, 0); };
    void insert(int newData) { treeInsert(root, newData); };
    void clear() { treeClear(root); }
    BST copy() { return BST(treeCopy(root)); }
    void remove(int target){removeNode(root, target);}

   private:
    BSTNode *root;
    void preorderPrint(BSTNode *root);
    void treeInsert(BSTNode *&root, int newData);
    void printDepth(BSTNode *root, int depth);
    void treeClear(BSTNode *&root);
    BSTNode *treeCopy(BSTNode *root);
    void removeLargest(BSTNode *&root, int &largest);
    void removeNode(BSTNode *&root, int target);
};

int main(int argc, char const *argv[]) {
    BST tree;
    
    tree.insert(30);
    tree.insert(10);
    tree.insert(40);
    tree.insert(5);
    tree.insert(20);
    tree.insert(35);
    tree.insert(50);
    tree.insert(15);
    tree.insert(37);

    tree.print();
    cout << endl;
    int data;
    for (size_t i = 0; i < 4; i++)
    {
        cout << "Enter a number to remove: ";
        cin >> data;
        tree.remove(data);
        tree.print();
    }
    
    BST tree2 = tree.copy();
    tree.clear();
    tree2.print();
    return 0;
}  /// main

void BST::preorderPrint(BSTNode *root) {
    if (root != nullptr) {
        preorderPrint(root->left);
        preorderPrint(root->right);
        cout << root->data << " ";
    }
}

// void BST::treeInsert(BSTNode *&root, int newData) {
//     if (root == nullptr) {
//         root = new BSTNode(newData, nullptr, nullptr);
//     } else if (newData < root->data) {
//         treeInsert(root->left, newData);
//     } else if (newData > root->data) {
//         treeInsert(root->right, newData);
//     }
//     // else the element is in the tree
// }

// Non-recursive version
void BST::treeInsert(BSTNode *&root, int newData) {
    bool done = false;
    BSTNode *cursor = root;
    if (root == nullptr) {
        root = new BSTNode(newData);
        return;
    }
    while (!done) {
        if (newData < cursor->data) {
            if (cursor->left == nullptr) {
                cursor->left = new BSTNode(newData);
                done = true;
            } else {
                cursor = cursor->left;
            }
        } else if (newData > cursor->data) {
            if (cursor->right == nullptr) {
                cursor->right = new BSTNode(newData);
                done = true;
            } else {
                cursor = cursor->right;
            }
        } else
            done = true;
    }
}

void BST::printDepth(BSTNode *root, int depth) {
    if (root != nullptr) {
        printDepth(root->right, depth + 1);
        cout << setw(4 * depth) << ""  // Indent 4*depth
             << root->data << endl;
        printDepth(root->left, depth + 1);
    }
}

void BST::treeClear(BSTNode *&root) {
    if (root != nullptr) {
        treeClear(root->left);
        treeClear(root->right);
        delete root;
        root = nullptr;
    }
}

BSTNode *BST::treeCopy(BSTNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    BSTNode *leftPtr;
    BSTNode *rightPtr;
    leftPtr = treeCopy(root->left);
    rightPtr = treeCopy(root->right);
    return new BSTNode(root->data, leftPtr, rightPtr);
}

void BST::removeLargest(BSTNode *&root, int &largest) {
    BSTNode *removePtr;
    if (root == nullptr) {
        return;
    }
    if (root->right == nullptr) {
        largest = root->data;
        removePtr = root;
        root = root->left;
        delete removePtr;
    } else
        removeLargest(root->right, largest);
}

void BST::removeNode(BSTNode *&root, int target) {
    BSTNode *removePtr;
    if (root == nullptr) {return;}
    if (target < root->data){
        removeNode(root->left, target);
    }
    else if (target > root->data){
        removeNode(root->right, target);
    }
    else if (root->left == nullptr) {  // the target node is found
        removePtr = root;              // move the root to the right
        root = root->right;
        delete removePtr;
    } else if (root->right == nullptr) {  // move the root to the left
        removePtr = root;
        root = root->left;
        delete removePtr;
    } else{ // The left and right have nodes find and delete the largest on the
            // left and replace the root value with the one being deleted.
        removeLargest(root->left, root->data);
    }
}
