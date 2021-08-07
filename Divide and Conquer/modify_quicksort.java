public class modify_quicksort {
	public static void modify(int[] a, int idx) {
		int j = -1;
		int val = a[idx];
		for (int i = 0; i < a.length; ++i) {
			if (a[i] < val) {
				j++;
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
		int temp = a[j+1];
		a[j+1] = a[idx];
		a[idx] = temp;
	}
	public static void main(String[] args) {
		int[] a = {4,11,6,0,3,1,2,9,8, 100, -5};
		int val = 3;
		modify(a, val);
		for (int i : a) {
			System.out.print(i + " ");
		}
	}
}

// 4,11,6,0,3,1,2,9,8, 100, -5
// 0j,11,6,4,3,1,2,9,8,100,-5
// 0,-5j,6,4,3,1,2,9,8,100,11