#include <bits/stdc++.h>
using namespace std;

string t;
int k;

string solve() {
    unordered_set <char> window;
    int alpha[256] = {0};
    int left = 0, right = 0;

    for (int low = 0, high = 0; high < t.size(); ++high) {
        window.insert(t[high]);
        alpha[t[high]] += 1;

        while (window.size() > k) {
            if (--alpha[t[low]] == 0) {
                window.erase(t[low]);
            }
            low ++;
        }

        if (right - left < high - low) {
            right = high;
            left = low;
        }
    }

    return t.substr(left, right -left +1);
}

int main() {
    getline(cin, t);
    cin >> k;
    cout <<  solve();

}