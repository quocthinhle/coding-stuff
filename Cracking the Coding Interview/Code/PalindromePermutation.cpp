/*
 Given a string, write a function to check if it is a permutation of a palindrome. 
 A palindrome is a word or phrase that is the same forwards and backwards. // that means it's symmetry
 A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

*/

#include <bits/stdc++.h>
using namespace std;

unordered_map <char, int> map1;

string n;


bool PalindromePermutation() {
	for (int i=0; i<n.length(); ++i) {
		if ((int)n[i] > 90) {
			n[i] = char((int)n[i] - 32);
		}
		if (n[i] != ' ') {
			map1[n[i]] += 1;
		}
	}
	
	int countOdd = 0;
	
	for (auto i = map1.begin(); i!=map1.end(); i++) {
		cout << i->first << "\t" << i->second << "\n";
		if ((i->second)%2 != 0) {
			++countOdd;
		}
	}
	
	return countOdd <= 1;
}

int main() {
	getline(cin, n);
	cout << PalindromePermutation();
}