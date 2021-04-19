/*
    1.9 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0. 
    Hints:  #17, #74, #702
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector< vector<int> > mat;

void setRow(int i) {
    for (int j=0; j<n; ++j) {
        mat[i][j] = 0;
    }
}

void setCol(int j) {
    for (int i=0; i<n; ++i) {
        mat[i][j] = 0;
    }
}

void solve() {
    vector< pair<int,int> > coor;
    for (int i=0; i<n;  i++) {
        for (int j=0; j<n; j++) {
            if (mat[i][j] == 0) {
                coor.push_back(make_pair(i,j));
            }
        }
    }

    for (int i=0; i<coor.size(); ++i) {
        int x = coor[i].first;
        int y = coor[i].second;
        setRow(x);
        setCol(y);
    }
}

int main() {
    cin >> n;
    mat.resize(n);
    for (int i = 0; i < n; ++i) {
        mat[i].resize(n);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    solve();

    cout << "\n\n";

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}