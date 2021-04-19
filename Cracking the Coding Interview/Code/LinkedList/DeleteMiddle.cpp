#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

struct node {
    int data;
    node* next;
};

node* createNode (int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node* appendTail (node* head, int data) {
    node* tail = createNode(data);
    if (head == NULL) {
        return tail;
    }
    else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = tail;
        return head;
    }
}

int getSize(node* head) {
    if (head == NULL) {
        return 0;
    }
    else {
        int size = 0;
        node* temp = head;
        while (temp->next != NULL) {
            size += 1;
            temp = temp->next;
        }
        return size+1;
    }
}

node* deleteMiddle (node* head) {
    int size = getSize(head);
    int mid = size / 2;
    if (size <= 0 ) return NULL;
    else {
        int i = 0;
        node* temp = head;
        while (temp->next != NULL) {
            if (i==mid-1) {
                node* d = temp->next;
                temp->next = temp->next->next;
                delete(d);
            }
            ++i;
            temp = temp->next;
        }
        return head;
    }
}

void show (node* head) {
    if (head == NULL) {
        cout << "Empty list\n";
        return;
    }
    else {
        int i = 1;
        node* temp = head;
        while (temp->next != NULL) {
            cout << i << ": " << temp->data << endl;
            temp = temp->next;
            i += 1;
        }
        cout << i << ": " << temp->data << endl;
    }
}

int main() {
    node* head = createNode(1);
    appendTail(head, 2);
    appendTail(head, 3);
    appendTail(head, 4);
    appendTail(head, 5);
    appendTail(head, 6);
    appendTail(head, 7);

    show(head);

    cout << endl;

    head = deleteMiddle(head);

    show(head);
}