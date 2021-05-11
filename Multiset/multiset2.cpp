#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> a;
    a.insert(10);
    a.insert(10);
    a.insert(10);
    a.erase(a.find(10));

    cout << a[0];
}