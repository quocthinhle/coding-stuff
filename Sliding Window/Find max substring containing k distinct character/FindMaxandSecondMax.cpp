#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

void find(int arr[], int n) {
    int f = arr[0];
    int s = INT_MIN;
    int max_pos;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > f) {
            f = arr[i];
            max_pos = i;
        }
        if (i != max_pos) {
            s = max(s, arr[i]);
        }
    }

    cout << f << "\t" << s;
}

int main() {
    int arr[6] = {1,4,4,9,3,4};
    find(arr,6);
}