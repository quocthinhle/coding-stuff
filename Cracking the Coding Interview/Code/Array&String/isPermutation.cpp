#include <bits/stdc++.h>
using namespace std;

string a, b;
unordered_map <char, int> map1;
unordered_map <char, int> map2;

bool isPermutation() {
	int n1 = a.length();
	int n2 = b.length();
	
	if (n1 != n2) {
		return false;
	}
	
	for (int i=0; i<n1; ++i) {
		char key_a = a[i];
		char key_b = b[i];
		map1[key_a] += 1;
		map2[key_b] += 1;
	}
	
	for (int i=0; i<n1; ++i) {
		char key_a = a[i];
		char key_b = b[i];
		
		if (map1[key_a] != map2[key_a] || map1[key_b] != map2[key_b]) {
			return false;
		}
	}
	
	return true;
	
}

int main() {
	cin >> a >> b;
	cout << isPermutation();
}