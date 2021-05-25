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

int n, x;
vi arr;

pi solve() {
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] == x) return make_pair(i, j);
        else if (arr[i] + arr[j] < x) i++;
        else j--;
    }
    pi sad = make_pair(-1,-1);
    return sad;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    arr.resize(n);
    REP(i, 0, n-1) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> x;

    pi res = solve();

    cout << res.first << "\t" << res.second;
}

