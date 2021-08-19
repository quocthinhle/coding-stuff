// My own dumb solution:
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) return 0;
        
        int dp[] = new int[amount + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
    
        for (int i = 0; i < coins.length; ++i) {
            if (coins[i] <= amount)
                dp[coins[i]] = 1;
        }  
        
        int preCoin = -1;
        
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.length; ++j) {
                preCoin = i - coins[j];
                if (preCoin < 0) {
                    continue;
                } else {
                    if (dp[preCoin] != -1) {
                        dp[i] = (dp[i] == -1) ? dp[preCoin] + 1 : Math.min(dp[i], dp[preCoin] + 1);
                    }
                }
            }
        }
        
        return dp[amount];
    }
}

// 