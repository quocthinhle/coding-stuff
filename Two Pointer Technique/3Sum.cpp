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

struct Node {
    int first = -1;
    int second = -1;
};

struct Node make_node (int x, int y) {
    Node res;
    res.first = x;
    res.second = y;
    return res;
}



vector<vector<int>> solve() {
    int sz = n;
    vector<vector<int>> res;

    if (sz < 3) {
        return res;
    }

    map<int, Node> Map;

    for (int i = 0; i < sz - 1; ++i) {
        for (int j = 1; j < sz; ++j) {
            if (i != j) {
                Map[a[i] + a[j]] = make_node(i, j);
            }
        }
    }


    for (int i = 0; i < sz; ++i) {
        int f = Map[-a[i]].first;
        int s = Map[-a[i]].second;
        if ((f != -1 && s != -1) && (f != 0 || s != 0)) {
            if (i != f && i != s) {
                cout << a[i] << " " << a[f] << " " << a[s] << endl;
            }
        }
    }

    return res;
} 

void solve1() {
    int sz = n;

    sort(a.begin(), a.end());

    for (int i = 0; i < sz; ++i) {
        int target = -a[i];
        if (i > 1) {
            if (a[i] == a[i-1]) continue;
        }

        int left = 0, right = sz - 1;
        while (left < right) {
            if (left == i) ++left;
            if (right == i) --right;
            if (left < right) {
                int sum = a[left] + a[right];

                if (sum == target) {
                    cout << a[i] << " " << a[left] << " " << a[right] << "\n";
                    ++left;
                    while (left < right && a[left] != a[left-1]) ++left;
                    --right;
                    while (left < right && a[right+1] != a[right]) --right;
                }
                else if (sum > target) while (left < right && a[right-1] != a[right]) --right;
                else while (left < right && a[left] != a[left-1]) ++left;
            }
            else break;
        }
    }
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

    solve1();
}
