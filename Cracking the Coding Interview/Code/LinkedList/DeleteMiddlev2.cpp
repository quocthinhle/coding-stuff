#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

class LinkedList;

class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* root;
    public:
        LinkedList() {
            root = NULL;
        }

        LinkedList(int data) {
            root = new Node();
            root->data = data;
            root->next = NULL;
        }
        void addNode (int data) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;
            if (root == NULL) {
                root = newNode;
                return;
            }
            else {
                Node* temp = root;
                while (temp->next != NULL) {
                    cout << temp << "\tMemory\t" << root << "\n";
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void show() {
            Node* t = root;
            int i = 0;
            while (t->next != NULL) {
                cout << i << ": " << t->data << "\n";
                t = t->next;
                ++ i;
            }
            cout << i << ": " << t->data << "\n";
        }

        Node* getNode(int i) {
            Node* temp = root;
            int cnt = 0;
            while (temp->next != NULL) {
                if (i == cnt) {
                    return temp;
                }
                else {
                    ++cnt;
                    temp = temp->next;
                }
            }
            if (cnt == i) {
                return temp;
            }
        }

        bool disappear(Node* current) {
            Node* t = current->next;
            current->data = t->data;
            current->next = t->next;
            delete t;
            return true;
        }

};



int main() {
    LinkedList* t = new LinkedList(1);
    t->addNode(3);
    t->addNode(4);
    t->addNode(5);
    t->addNode(6);
    t->show();
    t->disappear(t->getNode(1));
    cout << endl;
    t->show();
}