import java.util.ArrayDeque;

import java.util.Deque;

public class SlidingWindowMaximum {
	public static int[] Solve(int[] arr, int k) {
		Deque<Integer> dq = new ArrayDeque<Integer>();
		int[] res = new int[arr.length - k + 1];
		int CurrentIndex = 0;
		
		for (int i = 0; i < arr.length; ++i) {
			while (!dq.isEmpty() && arr[dq.getLast()] < arr[i]) {
				dq.removeLast();
			}

			dq.addLast(i);

			if (i - dq.getFirst() >= k) {
				dq.removeFirst();
			}

			if (i >= k - 1) {
				res[CurrentIndex++] = arr[dq.getFirst()];
			}
			
		}

		return res;
	}

	public static void test() {
		System.out.println("asdasd");
		char c = 'a';
		String c = "add";
		System.out.println(c.length());
		System.out.println(c - 97);
	}
	public static void main(String[] args) {
		int[] arr = {1,3,-1,-3,5,3,6,7};
		int k = 3;
		int[] res = Solve(arr, k);
		// for (int i = 0; i < res.length; ++i) {
		// 	System.out.print(res[i] + " ");
		// }
		test();
	}
	
	
}
