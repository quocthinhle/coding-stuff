public class LongestSubstringWithoutRepeatingCharacters {
	// "abcabcbb" -> "abc" -> 3
	public static int Solve(String s) {
		int Size = s.length();
		int start = 0, end = 0, res = 0;

		int track[] = new int[256];

		while (end < Size) {
			while (end < Size && track[s.charAt(end)] == 0) {
				++track[s.charAt(end)];
				++end;
			}

			res = Math.max(res, end - start);

			while (end < Size && track[s.charAt(end)] != 0) {
				--track[s.charAt(start)];
				++start;
			}
		}

		return res;
	}

	public static void main(String[] args) {
		String s = "dvdf";
		System.out.println("Length of the longest Substring: " + Solve(s));
	}
}