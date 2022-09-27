/**
 *   @file: bin-trees.cc
 * @author: Nasseef Abukamail
 *   @date: September 20, 2022
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct BSTNode{
    BSTNode(int newData, BSTNode *leftptr = nullptr, BSTNode *rightptr = nullptr){
        data = newData;
        left = leftptr;
        right = rightptr;
    }
    int data;
    BSTNode *left;
    BSTNode *right;
};

class BST{
public:
    BST(){root = nullptr;}
    void print(){printDepth(root, 0);};
    void insert(int newData){treeInsert(root, newData);};
    void clear(){treeClear(root);}
private:

    BSTNode *root;
    void preorderPrint(BSTNode * root);
    void treeInsert(BSTNode *&root, int newData);
    void printDepth(BSTNode * root, int depth);
    void treeClear(BSTNode *& root)

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
    tree.clear();
    return 0;
} /// main

void BST::preorderPrint(BSTNode * root)
{
    if (root != nullptr)
    {
        preorderPrint(root->left);
        preorderPrint(root->right);
        cout << root->data << " ";
    }
}

void BST::treeInsert(BSTNode *&root, int newData)
{
  	if (root == nullptr){
    		root = new BSTNode(newData, nullptr, nullptr);
		}
   	else  if (newData < root ->data){
          treeInsert(root->left, newData);
		}
    	else if (newData > root->data){
          treeInsert (root->right, newData);
		}
    // else the element is in the tree
} 

void BST::printDepth(BSTNode* root, int depth) 
{ 
    if (root != nullptr) 
    { 
        printDepth(root->right, depth+1); 
        cout << setw(4*depth) << "" // Indent 4*depth
             << root->data << endl; 
        printDepth(root->left, depth+1); 
    } 
} 

void BST::treeClear(BSTNode *& root)
{
    if (root != nullptr)
    {
        treeClear(root->left);
        treeClear(root->right);
        delete root;
        root = nullptr;
    }
}
