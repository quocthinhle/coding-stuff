#include <bits/stdc++.h>

using namespace std;
string n;
unordered_map <char, int> myMap;


bool isUnique() {
	for (int i=0; i<n.length(); ++i) {
		char key = n[i];
		if (myMap[key] == 0) {
			myMap[key] = 1;
		}
		if (myMap[key] == 1) {
			return false;
		}
	}
	return true;
}

int main() {
    
    cin >> n;
    cout << isUnique();
}