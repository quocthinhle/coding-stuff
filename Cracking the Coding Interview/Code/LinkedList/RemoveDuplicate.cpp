#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

unordered_map <int, bool> track;

struct node {
    int data;
    node* next;
};

node* createNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node* append(node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(data);
        return head;
    }
}

void show(node* head) {
    int i = 1;
    node* temp = head;
    while (temp->next != NULL) {
        cout << i << ": " << temp->data << "\n";
        i += 1;
        temp = temp->next;
    }
    cout << i << ": " << temp->data << "\n";
}

void RemoveDuplicate(node* head) {
    node* temp = head;
    while (temp->next != NULL) {
        track[temp->data] = true;

        if (track[(temp->next)->data]) {
            node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete(nodeToDelete);
        }
        else {
            temp = temp->next;
        }
        
    }
}

int main() {
    node* head = createNode(3);
    append(head, 1);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 1);
    append(head, 3);
    append(head, 7);
    append(head, 1);
    append(head, 1);
    append(head, 8);
    show(head);
    cout << endl << endl;
    RemoveDuplicate(head);
    show(head);
}