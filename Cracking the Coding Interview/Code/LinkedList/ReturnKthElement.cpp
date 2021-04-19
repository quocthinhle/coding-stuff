#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int n, temp;

struct node {
    int data;
    node* next;
};

node* createNode(int data) {
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;
    return temp;
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

node* appendTail (node* head, int data) {
    node* child = createNode(data);
    if (head == NULL) {
        head = child;
    }
    else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
    return head;
}

int getKthElement (int k, node* head) {
    if (head == NULL) {
        return -1;
    }
    else {
        node* temp = head;
        int i = 1;
        while (temp->next != NULL) {
            if (k==i) {
                return temp->data;
            }
            else {
                ++i;
                temp = temp->next;
            }
        }
        cout << "k = " << k << "\ti = " << i << endl;
        if (k == i) {
            return temp->data;
        }
        else {
            return -1;
        }
    }
}

int main() {
    node* head = NULL;
    cin >> n;
    while (n--) {
        cin >> temp;
        if (head == NULL) {
            head = createNode(temp);
        }
        else {
            head = appendTail(head, temp);
        }
    }

    show(head);
    cout << endl;
    cout << getKthElement(6, head);

}