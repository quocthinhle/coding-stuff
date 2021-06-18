class Solution {
	public int Partition(int[] arr, int left, int right) {
		int j = left - 1;
		int pivot = arr[right];
		for (int i = left; i < right; ++i) {
			if (arr[i] > pivot) {
				++j;
				arr[i] = getItself(arr[j], arr[j] = arr[i]);
			}
		}

		arr[j+1] = getItself(arr[right], arr[right] = arr[j + 1]);
		return j + 1;
	}

	public int QuickSelect(int[] arr, int low, int high, int k) {
		while (low <= high) {
			int pi = Partition(arr, low, high);
			if (pi == k - 1) return arr[pi];
			else if (pi > k - 1) high = pi - 1;
			else low = pi + 1;
		}
		return -1;
	}

	public int getItself(int a, int b) {
		return a;
	}

	public int KthLargestElement(int[] arr, int k) {
		if (k > arr.length) return -1;
		if (k <= 0) return -1;
		else return QuickSelect(arr, 0, arr.length - 1, k);
	}
	
}

public class KthLargestElement {
	public static void main(String[] args) {

	}
}