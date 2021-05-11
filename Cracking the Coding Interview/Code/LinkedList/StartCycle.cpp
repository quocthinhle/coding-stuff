#include <bts/stdc++.h>
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

        Node* checkCycle (LList* a) {
            Node* fast = a->root;
            Node* slow = a->root;

            if (a->root == NULL || a->root->next == NULL) return NULL;

            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
                if (slow = fast) {
                    break;
                }
            }

            if (fast == NULL || fast->next == NULL) {
                return NULL;
            }

            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return fast;
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


};

