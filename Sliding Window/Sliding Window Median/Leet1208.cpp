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

string a, b;
int maxCost;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, a);
    getline(cin, b);
    cin >> maxCost;

    int left = 0, right = 0, res = 0;
    int sz = a.length();
    int currentCost = 0;

    while(right < sz) {
        int dist = (int)a[right] - (int)b[right];

        currentCost += abs(dist);

        while (currentCost > maxCost) {
            int left_dist = (int)a[left] - (int)b[left];
            currentCost -= abs(left_dist);
            ++left;
        }

        res = max(res, right - left + 1);

        right++;
    }

    cout << res;

}

