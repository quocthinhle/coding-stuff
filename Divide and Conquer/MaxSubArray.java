public class MaxSubArray {
	public static int MaxCrossingArray(int[] arr, int l, int mid, int r) {
		int LeftSum = 0, maxLeft = Integer.MIN_VALUE;
		int RightSum = 0, maxRight = Integer.MIN_VALUE;

		for (int i = mid; i >= l; --i) {
			LeftSum += arr[i];
			maxLeft = Math.max(maxLeft, LeftSum);
		}

		for (int i = mid + 1; i <= r; ++i) {
			RightSum += arr[i];
			maxRight = Math.max(maxRight, RightSum);
		}

		return Math.max(Math.max(maxLeft, maxRight), maxLeft + maxRight);
	}

	public static int MaxSubArrayCalc(int[] arr, int l, int r) {
		if (l == r) return arr[l];

		int mid = (l+r)/2;

		int LeftSum = MaxSubArrayCalc(arr, l, mid);
		int RightSum = MaxSubArrayCalc(arr, mid + 1, r);
		int CrossSum = MaxCrossingArray(arr, l, mid, r);

		return Math.max(LeftSum, Math.max(RightSum, CrossSum));
	}

	public static int Solve(int[] arr) {
		return MaxSubArrayCalc(arr, 0, arr.length - 1);
	}

	public static void main(String[] args) {
		int[] arr = {-2,1,-3,4,-1,2,1,-5,4};
		System.out.println("Max Sub-Array sum is: " + Solve(arr));
	}
}