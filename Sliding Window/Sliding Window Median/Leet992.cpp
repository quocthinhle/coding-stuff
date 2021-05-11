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
int sz, k;

int CountDistinct(vi &a, int k) {
    int sz = a.size();
    int left = 0, right = 0;
    int res = 0;
    vi track(sz+1, 0);

    for (int i = 0; i < sz; ++i) {
        ++track[a[i]]; 
    }

    int curr = 0;

    while (right < sz) {
        
        if (curr == k) {
            ++res;
        }

    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> sz;
    a.resize(sz);
    REP(i, 0, sz-1) {
        cin >> a[i];
    }
    cin >> k;


}

