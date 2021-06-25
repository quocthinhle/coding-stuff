#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node* left;
        Node* right;
        int data;

        Node (int data) {
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
};

class BinarySearchTree {
    private:
        Node* root;
    
    public:
        BinarySearchTree() {
            root = NULL;
        }

        BinarySearchTree(int data) {
            root = new Node(data);
        }

        Node* AddNode(Node* n, int data) {
            if (!n) {
                n = new Node(data);
            }
            else if (n->data < data) {
                n->right = AddNode(n->right, data);
            }
            else if (n->data > data) {
                n->left = AddNode(n->left, data);
            }

            return n;
        }

        void inOrder(Node* n) {
            if (n == NULL) return;
            inOrder(n->left);
            cout << n->data << " ";
            inOrder(n->right);
        }

        Node* SearchNode (int data, Node* root) {
            if (root == NULL || root->data == data) return root;

            if (root->data < data) return SearchNode(data, root->right);

            return SearchNode(data, root->left);
        }

        void Search(int data){
            Node* temp = root;
            Node* result = SearchNode(data, temp);
            if (result) cout << "\nFound!";
            else cout << "\nNot Found!";
        }

        Node* GetRoot () {
            return this->root;
        }
};

int main() {
    BinarySearchTree*  bst = new BinarySearchTree(1);
    bst->AddNode(bst->GetRoot(), 4);
    bst->AddNode(bst->GetRoot(), 5);
    bst->AddNode(bst->GetRoot(), 6);
    bst->AddNode(bst->GetRoot(), -7);
    bst->AddNode(bst->GetRoot(), 0);
    bst->AddNode(bst->GetRoot(), 9);
    bst->inOrder(bst->GetRoot());
}
