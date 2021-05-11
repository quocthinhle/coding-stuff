#include <bits/stdc++.h>
using namespace std;


#include <iostream>
#include <string>
using namespace std;

int MathChallenge(int num) {
  string s = to_string(num);
  set<char> check;

  if (s.size() == 1) return -1;

  for (int i = 0; i < s.size(); ++i) {
    check.insert(s[i]);
  }

  if (check.size() == 1) return -1;
  
  int size = s.size();
  int i, j;

  for ( i = size-1; i > 0; --i) {
    if (s[i] > s[i-1]) break;
  }

  if (i==0) return -1;

  char x = s[i-1];
  int temp = i;
  for (j = i+1; j<size; ++j) {
    if (s[j] > x && s[j] < s[temp]) {
      temp = j;
    }
  }

  char temp1 = s[temp];
  s[temp] = s[i-1];
  s[i-1] = temp1;

  sort (s.begin()+i, s.begin()+size);

  num = stoi(s);

  cout << num;

  // code goes here  
  return num;

}

int main() {
    int i = 43201;
    MathChallenge(i);
}