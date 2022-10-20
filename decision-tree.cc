/**
 *   @file: decision-tree.cc
 * @author: Nasseef Abukamail
 *   @date: October 19, 2022
 *  @brief: Add Description
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stack>

using namespace std;

/// Constants and function prototypes
struct Node {
    Node(string t, int k, Node *leftPtr = nullptr, Node *rightPtr = nullptr) {
        text = t;
        key = k;
        left = leftPtr;
        right = rightPtr;
    }
    string text;
    int key;
    Node *left;
    Node *right;
};

class DecisionTree {
   public:
    DecisionTree() { root = nullptr; }
    // void insert(string q, int k){treeInsert(root, q, k);};
    void buildTree(string filename);
    void print() { printTree(root); }
    void decision();

   private:
    Node *root;
    void treeInsert(Node *&root, string q, int k);
    void printTree(Node *root);
};

int main(int argc, char const *argv[]) {
    DecisionTree credit;
    credit.buildTree("decision.txt");
    // credit.print();
    credit.decision();

    return 0;
}  /// main

void DecisionTree::buildTree(string filename) {
    ifstream inp(filename);
    if (inp.fail()) {
        cout << "Error: file " << filename << " not found" << endl;
        exit(0);
    }
    int key;
    string text;

    while (inp >> key) {
        inp.ignore();
        getline(inp, text);
        treeInsert(root, text, key);
    }
    inp.close();
}
void DecisionTree::treeInsert(Node *&root, string t, int k) {
    if (root == nullptr) {
        root = new Node(t, k);
    }
    if (k < root->key) {
        treeInsert(root->left, t, k);
    }
    if (k > root->key) {
        treeInsert(root->right, t, k);
    }
}

void DecisionTree::printTree(Node *root) {
    stack<Node *> stk;
    Node *curr = root;
    while (curr != nullptr || !stk.empty()) {
        if (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        } else {
            curr = stk.top();
            cout << curr->key << endl;
            stk.pop();
            curr = curr->right;
        }
    }
}
// void DecisionTree::printTree(Node *root){
//     if (root != nullptr)
//     {
//         printTree(root->left);
//         cout << "Key: " << root->key << ", Text: " << root->text << endl;
//         printTree(root->right);
//     }
// }

void DecisionTree::decision() {
    string answer;
    while (true) {
        cout << root->text << endl;
        cin >> answer;
        if (answer == "y") {
            root = root->right;
        } else if (answer == "n") {
            root = root->left;
        }
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->text << endl;
            break;
        }
    }
}