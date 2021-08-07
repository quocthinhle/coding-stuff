public class LongestSubSequence {
	public static int longestPalindrome(String s) {
        int sz = s.length();
        int[][] dp = new int[sz][sz];

		int start = 0;
		int end = 0;
        
        for (int i = 0; i < sz; ++i) {
            dp[i][i] = 1;
			start = i;
			end = i;
        }
        
        for (int len = 2; len <= sz; ++len) {
            for (int i = 0; i <= sz - len; ++i) {
                int j = i + len - 1;
                if (len == 2 && s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = 2;
					start = i;
					end = j;
                }
                else if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1] + 2;
					start = i;
					end = j;
                }
                else {
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
                }
            }
			System.out.println("Start: " + start +  " - End: " + end);
        }

		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				System.out.print(dp[i][j] + " ");
			}
			System.out.println();
		}
		
        return dp[0][sz-1];
    }

	public static void main(String[] as) {
		System.out.println(longestPalindrome("aacabdkacaa"));
	}
}