#include <bits/stdc++.h>
#define S second
#define F first
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define SQ(a) (a) * (a)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

string s;
int k;
int track[26] = {0};

int solve(string s, int k)
{
    int left = 0, right = 0, res = 0;
    int sz = s.size();
    int distinct = 0;
    while (right < sz)
    {
        if (track[s[right]] == 0)
        {
            ++distinct;
        }

        ++track[s[right]];

        while (distinct > k)
        {
            --track[s[left]];
            if (track[s[left]] == 0)
            {
                --distinct;
            }
            left++;
        }

        res += (right - left + 1);

        ++right;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, s);
    cin >> k;
    cout << solve(s, k);
}
