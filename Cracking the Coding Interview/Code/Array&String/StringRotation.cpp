#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

bool isRotation(string s1, string s2);
bool isSubString1(string s1, string s2);
bool isSubString2(string s1, string s2);

/*
    For example: 
        s1 = "waterbottle" and we rotate around the "wat" so s2 = "erbottlewat"

        So: s1 = xy and s2 = yx

        How to find x and y.

        It obviously to realize that yx is a subString of xyxy that means -> two times of s1

*/

bool isRotation(string s1, string s2) {
    string xyxy = "";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < s1.length(); ++j) {
            xyxy += s1[j];
        }
    }

    return isSubString(xyxy, s2);
}

bool isSubString1(string root, string check) {
    for (int i = 0; i < root.length() - check.length(); ++i) {
        int j;
        for (j = 0; j < check.length(); ++j) {
            if (root[i+j] != check[j]) break;
        }
        if (j == check.length()) return true;
    }
    return false;
}

bool isSubString2(string root, string check) {
    int pos = 0;
    int i;
    for (i = 0; i < root.length(); ++i) {
        if (pos == check.length()) {
            break;
        }
        if (check[pos] == root[i]) {
            pos += 1;
        }
        else {
            t = 0;
        }
    }
    return t == check.length();
    // if we want to get position just do return i-t;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << isRotation(s1,s2);
}