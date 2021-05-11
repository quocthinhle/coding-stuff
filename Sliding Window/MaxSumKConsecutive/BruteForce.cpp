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

    for (int i = 0; i < n-k+1; i++) {
        int temp = 0;
        for (int j = i; j < i+k; ++j) {
            temp += c[j];
        }
        sum = max(sum,temp);
    }

    cout << sum;

}
