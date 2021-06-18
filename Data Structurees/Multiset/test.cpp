#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<int> ans;
    while (cin >> x) {
        ans.push_back(x);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}