/* : Given an image represented by an NxN matrix, where each pixel in the image is 4 
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?  */

#include <bits/stdc++.h>
using namespace std;

int n;



bool rotate90 (vector< vector<int> > &mat) {
    for (int layer = 0; layer < n/2; ++layer) {
        int first = layer;
        int last = n-1-layer;
        
        for (int i=first; i<last; i++) {
            int offset = i - first;

            int top = mat[first][i];

            // left -> top
            mat[first][i] = mat[last-offset][first];

            // bottom -> left
            mat[last-offset][first] = mat[last][last-offset];

            // right -> bottom
            mat[last][last-offset] = mat[i][last];

            // top -> bottom 
            mat[i][last] = top;

        }
    }
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

    rotate90(mat);

    cout << "After: \n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }


}