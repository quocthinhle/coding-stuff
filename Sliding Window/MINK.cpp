#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll N, k, temp, T;
vector<ll> a;
vector<ll> ans;


int main() {
    cin >> T;
    while (T--) {
        cin >> N >> k;
        a.resize(N);
        for (ll i = 0; i < N; ++i) {
            cin >> temp;
            a[i] = (temp);
        }
        deque<ll> dq;
        while (dq.size()) dq.pop_back();
        ans.resize(N-k+1);

        for (ll i = 0; i < N; ++i) {
            while (dq.size() && a[dq.back()] > a[i]) dq.pop_back();

            dq.push_back(i);

            if (i - k >= dq.front()) dq.pop_front();

            if (i + 1 - k >= 0) ans[i+1-k] = a[dq.front()];
        }

        ll nax = ans[0];
        for (ll i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
            nax = max(nax, ans[i]);h
        }
        cout << "\n";
    }
}