#include <bits/stdc++.h>
using namespace std;

void fun(int x) {
    if (x > 0) {
        cout << x << " ";
        fun(x-1);
        fun(x-1);
        fun(x-1);
    }
}

// nested recursion
void fun1(int x) {
    if (x > 100) return x - 10;
    return fun1(fun1(x+11));
}

int main() {
    int n = 3;
    fun(3);
    return 0;
}