// Mine dump solution
class Solution {
    public boolean canJump(int[] nums) {
        int sz = nums.length;
        boolean[] track = new boolean[sz];
        
        track[0] = true;
        for (int i = 1; i < sz; ++i) {
            track[i] = mark(track, nums, i);
			if (track[i] == false) return false; 
        }
        
        return track[sz - 1];
    }
    
    public boolean mark(boolean[] track, int[] nums, int i) {
        if (track[i - 1] == false) return false;
        for (int idx = 0; idx < i; ++idx) {
            if (i - idx <= nums[idx]) {
                return true;
            }  
        }
        return false;
    }
}

// Greedy Solution
class Solution {
    public boolean canJump(int[] nums) {
        int sz = nums.length;
        int farest = 0;
        
        for (int i = 0; i < sz; ++i) {
			if (farest < i) {
				return false;
			}
			farest = Math.max(farest, i + nums[i]);
		}

		return true;
    }
}

// [2,3,1,1,4] -> 0,2	

// DP Solution
class Solution {
    
}