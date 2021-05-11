#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int n, k;
vector<int> c;

int main() {
    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    cin >> k;

    if (k>n) {
        return 0;
    }

    int sum = 0;

    for (int i = 0; i < k; ++i) {
        sum += c[i];
    }

    for (int i = k; i < n; ++i) {
        sum = max (sum, sum-c[i-k]+c[i]);
    }

    cout << sum;
}