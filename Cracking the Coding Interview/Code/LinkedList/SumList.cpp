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
        friend LList* SumList(Node* , Node*);
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

        Node* getRoot() {
            return this->root;
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

LList* SumList(Node* f, Node* s) {
    LList* r = new LList();
    Node* temp  = new Node();
    int carry = 0;
    while (f != NULL && s != NULL) {
        int res = f->data + s->data + carry;
        
        if (carry) --carry;

        if (res >= 10) {
            res -= 10;
            carry += 1;
        }

        r->append(res);

        s = s->next;
        f = f->next;
    }

    if (f == NULL && s == NULL) {
        return r;
    }
    else {
        while (f != NULL) {
            int res = f->data + carry;
            if (carry) --carry;
            r->append(res);
            f = f->next;
        }
        while (s != NULL) {
            int res = s->data + carry;
            if (carry) --carry;
            r->append(res);
            s = s->next;
        }
        return r;
    }
}

int main() {
    LList *first = new LList();
    LList *second = new LList();
    first->append(7);   first->append(1);   first->append(6); 
    second->append(5);  second->append(9);  second->append(2); second->append(1); second->append(4);
    LList* r = SumList(first->getRoot(), second->getRoot());
    r->show();
}