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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);

    ms.erase(2);

    vector<int> a;
    
    this is the first time i have been here and it's kind of crazy whenever you want to think about that,
    and sometimes, i just feel like it's just only me in the world and that's it.

    for (auto it = ms.begin(); it != ms.end(); it++) {
        cout << *it << " ";
    }

}


