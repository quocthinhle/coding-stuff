// Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

public class Leet1863_SumXorOfTotalSubset {
    public int subsetXORSum(int[] nums) {
        int sz = nums.length;
        int[] selections = new int[nums.length];
        List<Integer> lst = new ArrayList<Integer>();
        backtrack(0, sz - 1, selections, lst, nums);
        int res = 0;
        for (int i = 0; i < lst.size(); ++i) {
            res += lst.get(i);
        }
        return res;
    }
    
    void backtrack(int turn, int sz, int[] selections, List<Integer> lst, int[] nums) {
        for (int i = 0; i <= 1; i++) {
            selections[turn] = i;
            if (turn == sz) {
                process(selections, lst, nums);
            } else {
                backtrack(turn + 1, sz, selections, lst, nums);
            }
        }
    }
    
    void process(int[] selections, List<Integer> lst, int[] nums) {
        int res = -1;
        boolean first = false;
        for (int i = 0; i < selections.length; ++i) {
            if (selections[i] != 0) {
                if (first == false) {
                    first = true;
                    res = nums[i];
                } else {
                    res = res ^ nums[i];
                }
            }
        }
        if (first == true) {
            lst.add(res);
        } else
            return;
    }
}