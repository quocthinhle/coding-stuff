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

        friend Node* checkIntersection(LList *a, LList *b);

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

        int getSize() {
            int sz = 0;
            Node* t = root;
            while (t != NULL) {
                sz += 1;
                t = t->next;
            }
            return sz;
        }

};

Node* checkIntersection(LList *a, LList *b) {
    int sz1 = a->getSize();
    int sz2 = b->getSize();
    
    Node* head1 = a->root;
    Node* head2 = b->root;

    if (sz1 > sz2) {
        for (int i = 0; i < sz1-sz2; ++i) {
            head2 = head2->next;
        }
    }

    while (head1 != NULL  && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }


        head2 = head2->next;
        head1 = head1->next;
    }

    return NULL;
}

int main() {
    LList* a = new LList();
    LList* b = new LList();

    a->append(5);
    a->append(6);
    a->append(6);
    cout << a->getSize();
}