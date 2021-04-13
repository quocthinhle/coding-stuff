#include <bits/stdc++.h>
using namespace std;

string n;

void solve() {
	int numOfSpaces = 0;
	int len = n.length();
	for (int i=0; i<len; i++) {
		if (n.at(i) == ' ') {
			++numOfSpaces;
		}
	}

	int expected_Length = n.length() + 2*numOfSpaces;
	vector<char> out;
	out.resize(expected_Length);
	int j = expected_Length - 1;
	for (int i = len - 1; i>=0; --i) {
		if (n[i] != ' ') {
			out[j] = n[i];
			--j;
		}
		else {
			out[j] = '0';
			out[j-1] = '2';
			out[j-2] = '%';
			j -= 3;
		}
	}
	
	for (int i=0; i<expected_Length; ++i) {
		cout << out[i];
	}

}

int main() {
	getline(cin, n);
	solve();
}