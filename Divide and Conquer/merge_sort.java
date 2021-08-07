public class merge_sort {
	public static void mergeSort(int[] a, int L, int R) {
		if (L < R) {
			int mid = (L + R) / 2;
			mergeSort(a, L, mid);
			mergeSort(a, mid + 1, R);
			merge(a, L, mid, R);
		}
	}

	public static void merge(int[] a, int L, int m, int R) {
		int[] left = new int[m - L +1];
		int[] right = new int[R - m];

		for (int i = 0; i < m - L + 1; ++i) {
			left[i] = a[L + i];
		}

		for (int i = 0; i < R - m; ++i) {
			right[i] = a[m + 1 + i];
		}

		int idx1 = 0, idx2 = 0;
		int idx = L;
		while (idx1 < m - L + 1 && idx2 < R - m) {
			if (left[idx1] > right[idx2]) {
				a[idx] = right[idx2++];
			} else {
				a[idx] = left[idx1++];
			}
			++idx;
		}

		while (idx1 < m - L + 1) {
			a[idx++] = left[idx1++];
		}

		while (idx2 < R - m) {
			a[idx++] = right[idx2++];
		}
	}

	public static void printArray(int[] a) {
		for (int i = 0; i < a.length; ++i) {
			System.out.print(a[i] + " ");
		}
		System.out.println("");
	} 
	public static void main(String[] args) {
		int[] a = {1,3,2,-6,7,9,-11};
		printArray(a);
		mergeSort(a, 0, a.length - 1);
		printArray(a);
	}
}