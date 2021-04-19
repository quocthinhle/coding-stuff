/* : Given an image represented by an NxN matrix, where each pixel in the image is 4 
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?  */

#include <bits/stdc++.h>
using namespace std;

int n;

void transposed(vector< vector<int> > &mat) {
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void reverseRow (vector< vector<int> > &mat) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n/2; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n-1-j];
            mat[i][n-1-j] = temp;
        }
    }
}

bool rotate90 (vector< vector<int> > &mat) {
    
    return true;
}

int main() {
    cin >> n;

    vector< vector<int> > mat;
    mat.resize(n);
    for (int i=0; i<n; ++i) {
        mat[i].resize(n);
    } 

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    

    cout << "Before: \n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    transposed(mat);
    reverseRow(mat);

    cout << "After: \n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }


}