// Approach: DP
/*
	Let's call ms(i) is the max sum ending at idx i
	So at idx i, we have two choices:
		-> ms(i) = ms(i-1) + a[i];
		or ms(i) = a[i];
		why not ms(i) = ms(i-1), because:  it's sub array sum, must take the a[i] value.
*/

public class Leet53_MaximumSubArray {
	private static void solve(int[] a) {
		int[] solution = new int[a.length + 1];
		solution[0] = 0;
		for (int i = 1; i < solution.length; ++i) {
			solution[i] = Math.max(solution[i-1] + a[i-1], a[i-1]);
		}

		int result = 0;
		for (int i = 1; i < solution.length; ++i) {
			result = Math.max(result, solution[i]);
		}
		System.out.println(result);
	}
	public static void main(String[] args) {
		int[] a = {-2,1,-3,4,-1,2,1,-5,4};
		solve(a);
	}
}
