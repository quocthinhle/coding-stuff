#include <bits/stdc++.h>
using namespace std;

bool solve();
bool edit();
bool removal();
bool insertion();

unordered_map <char, int> m1;
unordered_map <char, int> m2;
bool track[256];
string a, b;

bool solve() {

    if (a.length() == b.length()) {
        // So it's exactly edited
        return edit();
    }
    if (a.length()+1 == b.length()) {
        // Remove case
        return insertion();
    }
    if (b.length()+1 == a.length()) {
        return removal();
    }
    return false;
}

bool edit() {
    bool diff = false;
    for (int i=0; i<a.length(); ++i) {
        if (a[i] != b[i]) {
            if (diff) {
                return false;
            }
            diff = true;
        }
    }
    return true;
}

bool removal() {
    for (int i=0; i<b.length(); i++) {
        m2[b[i]] += 1;
    }

    for (int i=0; i<a.length(); ++i) {
        m1[a[i]] += 1;
    }

    int count = 0;

    for (int i=0; i<a.length(); ++i) {
        int key = (int)a[i];
        if (m1[a[i]] != m2[a[i]]  &&  track[key] == false) {
            track[key] = true;
            count += 1;
        }
    }

    return count <= 1;
}

bool insertion() {
    for (int i=0; i<b.length(); i++) {
        m1[b[i]] += 1;
    }

    for (int i=0; i<a.length(); ++i) {
        m2[a[i]] += 1;
    }

    int count = 0;

    for (int i=0; i<b.length(); ++i) {
        int key = (int)b[i];
        if (m1[b[i]] != m2[b[i]] && track[key] == false) {
            track[key] = true;
            count += 1;
        }
    }


    return count <= 1;
}

int main() {
    getline(cin, a);
    getline(cin, b);
    cout << solve();
}