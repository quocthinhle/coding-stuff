public class Leet5_LongestPalindromicSubstring {
	public static String longestPalindrome(String s) {
        int sz = s.length();
        boolean[][] dp = new boolean[sz][sz];

		int start = 0;
		int end = 0;
        
        for (int i = 0; i < sz; ++i) {
            dp[i][i] = true;
			start = i;
			end = i;
        }
        
        for (int len = 2; len <= sz; ++len) {
            for (int i = 0; i <= sz - len; ++i) {
                int j = i + len - 1;
                if (len == 2 && s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = true;
                }
                else if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1];
                }
                
				if (dp[i][j] && j - i >= end - start) {
					start = i;
					end = j;
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
		
        return s.substring(start, end+1);
    }

	public static void main(String[] as) {
		System.out.println(longestPalindrome("aacabdkacaa"));
	}
}