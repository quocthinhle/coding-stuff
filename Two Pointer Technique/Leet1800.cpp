#include <bits/stdc++.h>
#define S second
#define F first
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define SQ(a) (a)*(a)

using namespace std;

typedef vector<int> vi;
typedef pair< int, int > pi;

vi a;
int n;

int solve() {
    int res = 0;
    int anchor = 0;
    int temp = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i-1]) {
            temp += a[i];
            res = max(temp, res);
        }
        else {
            res = max(temp, res);
            anchor = i;
            temp = a[anchor];
        }
    }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    REP(i, 0, n-1) {
        cin >> a[i];
    }

    cout << solve();

}

