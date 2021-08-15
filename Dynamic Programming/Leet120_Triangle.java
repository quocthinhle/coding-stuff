class Solution {    
    public int minimumTotal(List<List<Integer>> tria) {
        int[] dp = new int[tria.get(tria.size() - 1).size()];
        for (int i = 0; i < dp.length; ++i) {
            dp[i] = tria.get(tria.size()-1).get(i);
        }
        
        for (int layer =  tria.size() - 2; layer >= 0; --layer) {
            for (int i = 0; i < layer + 1; ++i) {
                dp[i] = Math.min(dp[i], dp[i + 1]) + tria.get(layer).get(i);
            }
        }
        
        return dp[0];
    }
}

// Backtrack solution time limit exceed, yeet! moved to dp afterwards.

/* Bottom up

2
|  \
3	4
| \ | \
6	5	7
| \ | \ | \
4	1	8	3
| \ | \ | \ | \
9	2	7	1	3

*/