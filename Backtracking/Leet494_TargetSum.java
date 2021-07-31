class Solution {
    
    private int res = 0;
    
    public int findTargetSumWays(int[] nums, int target) {
        int selections[] = new int[nums.length];
        
        backtrack(0, nums.length - 1, selections, target, nums);
        
        return res;
    }
    
    private void backtrack(int Try, int sz, int[] selections, int target, int[] values) {
        for (int i = 0; i <= 1; ++i) {
            selections[Try] = i;
            if (Try == sz) {
                process(selections, target, values);
            } else {
                backtrack(Try + 1, sz, selections, target, values);
            }
        }
    }
    
    private void process(int[] selections, int target, int[] values) {
        int sum = 0;
        for (int i = 0; i < selections.length; ++i) {
            if (selections[i] == 1) {
                sum += values[i];
            } else {
                sum -= values[i];
            }
        }
        
        if (sum == target) ++this.res;
    }
}

// Sadly, this solution brought me a Time Limit Exceeded result.
// Going to learn Dynamic Programming then.