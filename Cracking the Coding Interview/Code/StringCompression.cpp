#include <bits/stdc++.h>
using namespace std;

string n;
unordered_map<char, int> m;
bool track[256];

string solve() {
    string res;
    stack<char> s;

    int curr = 0;
    s.push(n[0]);

    for (int i=0; i<n.length(); ++i) {
        if (n[i] == s.top()) {
            curr += 1;
        }
        else {
            res += s.top();
            res += to_string(curr);
            s.pop();
            s.push(n[i]);
            curr = 1;
        }
    }

    if (curr > 1) {
        res += s.top();
        res += to_string(curr);
    }
    if (curr == 1) {
        res += s.top();
        res += '1';
    }

    return res;
}

int main() {
    getline(cin, n);

    cout << solve();
}