#include <bits/stdc++.h>
#define S second
#define F first
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define SQ(a) (a)*(a)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int > pi;

using namespace std;

int main() {
    set<int> s;
    int ar[] = {1, 4, 5, 6, -7, 0, 9};
    s.insert(ar, ar+7);

    for (auto c : s) {
        cout << c << " ";
    }
}

// underlying the set is BST - Binary Search Tree
