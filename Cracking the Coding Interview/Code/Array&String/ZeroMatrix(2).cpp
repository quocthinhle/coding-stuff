#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

vector< vector<int> > mat;
int m, n;

void nullifyRow (int row) {
    for (int j = 0; j < n; ++j) {
        mat[row][j] = 0;
    }
}

void nullifyCol (int col)  {
    for (int i = 0; i < m; ++i) {
        mat[i][col] = 0;
    }
}

void setZeros() {
    bool colHasZero = false;
    bool rowHasZero = false;

    for (int i = 0; i < n; ++i) {
        if (mat[0][i] == 0) {
            rowHasZero = true;
            break;
        } 
    }

    for (int i = 0; i < m; ++i) {
        if (mat[i][0] == 0) {
            colHasZero = true;
            break;
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; ++i) {
        if (mat[i][0] == 0) {
            nullifyRow(i);
        }
    }

    for (int j = 1; j < n; ++j) {
        if (mat[0][j] == 0) {
            nullifyCol(j);
        }
    }

    if (colHasZero) {
        nullifyCol(0);
    }

    if (rowHasZero) {
        nullifyRow(0);
    }
}

int main() {
    cin >> m >>  n;
    mat.resize(m);

    for (int i = 0; i < m; ++i) {
        mat[i].resize(n);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
}