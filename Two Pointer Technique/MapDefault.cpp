// C++ program to illustrate a Map
// initialise with default value
#include <bits/stdc++.h>
using namespace std;

// Structure Node
pair<int, int> pi = make_pair(-1, -1);

// Driver Code
int main()
{
	// Map initialise with key value
	// pair with each pair mapped with
	// structure Node
	map<int, pair<int,int> > Map;
  

	// Print the default value of 1
	// store in Map
	cout << Map[40].second << endl;

	return 0;
}
