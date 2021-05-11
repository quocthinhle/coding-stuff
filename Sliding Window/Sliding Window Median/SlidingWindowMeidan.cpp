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

int N, k;
vi a, ans;
multiset<int> ms;

float EvenMedian (multiset<int> &ms, int& sz) {
    int a, b;
    int count = 0;
    for (int c : ms) {
        if (count == sz/2 - 1) {
            a = c;
        }
        if (count == sz/2) {
            b = c;
            break;
        }
        ++count;
    }

    return ((float)a+b)/2.0f;
}

float OddMedian(multiset<int> &ms, int& sz) {
    int count = 0;
    for (int c : ms) {
        if (count == sz/2) {
            return (float)c;
        }
        ++count;
    }
}

float MedianResult(multiset<int> &ms) {
    int sz = ms.size();
    if (sz%2 == 0) {
        return EvenMedian(ms, sz); 
    }

    else {
        return OddMedian(ms, sz);
    }
}

int main() {
    cin >> N >> k;
    a.resize(N);

    REP(i,0,N-1) {
        cin >> a[i];
    }


    REP(i, 0, k-1) {
        ms.insert(a[i]);
    }

    ans.PB(MedianResult(ms));

    REP(i, k, N-1) {
        ms.erase(ms.find(a[i-k]));
        // insert last element.
        ms.insert(a[i]);
        // calculate then push median to ans.
        //then push it back to the answer vector
        ans.PB(MedianResult(ms));
    }

    REP(i,0, ans.size()-1) {
        cout << ans[i] << " ";
    }

    return 0;
}