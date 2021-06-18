public class MinimumWindowSubstring {
	public static void main(String[] args) {
		String s = "ADOBECODEBANC";
		String t = "BANC";
		System.out.println("The longest substring of t in s is: " + Solve(s,t));
	}

	public static String Solve(String s, String t) {
		int Pane = s.length();
		int Window = t.length();
		int[] track = new int[256];
		for (int i = 0; i < Window; ++i) {
			++track[t.charAt(i)];
		}
		int start = 0, end = 0, left = 0, right = 0, res = Integer.MAX_VALUE;
		while (right < Pane) {
			if(--track[s.charAt(right++)] >= 0) Window--;

			while (Window == 0) {
				if (right - left < res) {
					start = left;
					res = right - left;
					end = right;
				}

				if (++track[s.charAt(left++)] > 0) Window++;
			}
		}

		return res == Integer.MAX_VALUE ? "" : s.substring(start, end);
	}
}