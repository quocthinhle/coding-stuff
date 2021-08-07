public class gridTraveler {
	// Recursion solution
	public static int solve(int a, int b) {
		System.out.println(a + " " + b);
		if (a == 1 && b == 1) {
			return 1;
		}
		else if (a == 0 || b == 0) return 0;
		else {
			return solve(a - 1, b) + solve(a, b - 1);
		}
	}
	public static void main(String[] args) {
		System.out.println(solve(2,3));
	}
}

// If we implement a memo-recursion -> it turns into DP