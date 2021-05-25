#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

// Rotate in-place and O(n) time-complexity O(1) space 
// 25/05/21 

int gcd(int a, int b) {
    while (a*b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;
}


void rotateRight(int arr[], int times, int size) {
    int gc = gcd(size, times);
    int j, k, temp;
    for (int i = 0; i < gc; ++i) {
        temp = arr[i];
        j = i;
        while (1) {
            k = j + times;

            if (k >= size) k -= size;

            if (k == i) break;

            arr[j] = arr[k];

            j = k;
        }

        arr[j] = temp;
    }
}



void rotateLeft(int arr[], int times, int size) {
    int gc = gcd(size, times);
    for (int i =0; i < gcd(times, size); ++i) {
        int j = size - 1 - i;
        int temp = arr[j];

        while (1) {

            int k = j - times;

            if (k < 0) k += size;

            if (k == size - 1 - i) break;

            arr[j] = arr[k];

            j = k;
        }

        arr[j] = temp;
    }
}

int main() {
    int a[6] = {1,2,3,4,5,6};
    int x;
    cin >> x;
    rotateLeft(a, x, 6);
    for (int i = 0; i < 6; ++i) cout << a[i] << " ";
}