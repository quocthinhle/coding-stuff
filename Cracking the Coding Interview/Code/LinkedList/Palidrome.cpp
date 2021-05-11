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

        bool checkPalidrome() {
            Node* fast = root;
            Node* slow = root;

            stack<int> s;

            while (fast != NULL && fast->next != NULL) {
                s.push(slow->data);
                slow = slow->next;
                fast = (fast->next)->next;
            }

            if (fast != NULL) {
                slow = slow->next;
            }

            while (slow != NULL) {
                int top = s.top();
                s.pop();
                if (top != slow->data) {
                    return false;
                }
                slow = slow->next;
            }

            return true;
        }

};

int main() {
    LList *T = new LList();
    T->append(1);
    T->append(2);
    T->append(3);
    T->append(2);
    T->append(1);
    cout << T->checkPalidrome();
}