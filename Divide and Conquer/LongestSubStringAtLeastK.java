
class SolutionDivideAndConquer {
	public static int longestSubstring(String s, int k) {
	    return solve(s, k, 0, s.length());
	}
	
	public static int solve(String s, int k, int start, int end) {
	    if (end < k) return 0;
	    int[] count = new int[26];
	    
	    for (int i = start; i < end; ++i) {
		count[s.charAt(i) - 'a']++;
	    }
	    
	    for (int mid = start; mid < end; ++mid) {
		if (count[s.charAt(mid) - 'a'] < k) {
		    int midNext = mid + 1;
		    while (midNext < end && count[s.charAt(midNext) - 'a'] < k) midNext++;
		    
		    return Math.max(solve(s,k,start,mid), solve(s, k, midNext, end));
		}
		else continue;
	    }
	    
	    return end - start;
	}
}

public class LongestSubStringAtLeastK {
	public static void main(String[] args) {
		String s = "thissssiiime";
		int k = 3;
		System.out.println(SolutionDivideAndConquer.longestSubstring(s, k));
	}
}
