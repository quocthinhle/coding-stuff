#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[i+l];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = arr[m+1+i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (int) ((l+r)/2);
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid , r);
}

int main() {
    int a[] = {5,4,3,2,1,1,3,4};
    int sz = 8;
    mergeSort(a, 0, sz - 1);
    for (int i = 0; i < sz; ++i) {
        cout << a[i] << " ";
    }
}