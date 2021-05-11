int solve(string s, int k) {
    int left = 0, right = 0, res = 0;
    int sz = s.size();
    int distinct = 0;
    while (right < sz) {
        if (track[right] == 0) {
            ++distinct;
            ++track[right];
        }

        while (distinct > k) {
            --track[left];
            if (track[left] == 0) {
                --distinct;
            }
            left++;
        }

        res += right - left + 1;

        ++right;
    }

    return res;
}