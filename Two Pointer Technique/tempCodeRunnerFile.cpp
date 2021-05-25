int currSum = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] <= a[i+1]) {
            currSum += a[i];
            if (i == n-2) {
                currSum += a[i+1];
            }
            res = max(res, currSum);
        }
        
        else {
            currSum += a[i];
            res = max(res, currSum);
            currSum = 0;
        }
    }
    return res;