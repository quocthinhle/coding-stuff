#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class LList {
    private: 
        Node* root;
    public:
        LList() {
            root = NULL;
        }
        LList(int data) {
            root = new Node();
            root->data = data;
            root->next = NULL;
        }
        void show() {
            Node* temp = root;
            int i = 0;
            while (temp->next != NULL) {
                cout << i << ": " << temp->data << "\n";
                temp = temp->next;
                ++i; 
            }
            cout << i << ": " << temp->data << "\n\n\n";
        }
        void append(int data) {
            Node* temp = new Node();
            temp->data = data;
            temp->next = NULL;
            if (root == NULL) {
                root = temp;
            }
            else {
                Node* it = root;
                while (it->next != NULL) it = it->next;
                it->next = temp; 
            }
        }

        void insertHead (int data) {
            Node* temp = new Node();
            temp->data = data;
            temp->next = NULL;
            if (root == NULL) {
                root = temp;
            }
            else {
                temp->next = root;
                root = temp;
            }
        }

        void partition(int data) {
            Node* head = root;
            Node* tail = root;
            while (root != NULL) {
                Node* next = root->next;
                if (root->data < data) {
                    root->next = head;
                    head = root;
                }
                else {
                    tail->next = root;
                    tail = root;
                }
                root = next;
            }
            tail->next = NULL;
            root = head;
        }

};

int main() {
    LList* t = new LList();
    t->append(1);
    t->append(2);
    t->append(8);
    t->append(6);
    t->append(3);
    t->append(4);
    t->append(5);
    t->insertHead(9);
    t->show();
    t->partition(5);
    t->show();
    return 0;
}