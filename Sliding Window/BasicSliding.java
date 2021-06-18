public class BasicSliding {

	// So in this problem the window is arr and the size of sliding is k
	// Just slide it.

	public static int Sliding(int[] arr, int k) {
		int Size = arr.length;
		int MaxSum = 0;

		for (int i = 0; i < k; ++i) {
			MaxSum += arr[i];
		}

		int SlidingSum = MaxSum;
		for (int i = k; i < Size; ++i) {
			SlidingSum = MaxSum - arr[i - k] + arr[i];
			MaxSum = Math.max(MaxSum, SlidingSum);
		}
		return MaxSum;
	}
	public static void main(String[] args) {
		int[] arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
		int k = 4;
		System.out.println(Sliding(arr, k));
	} 
}