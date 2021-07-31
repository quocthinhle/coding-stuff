public class ColorSelection {
	private static int[] selections = new int[5];
	private static String[] colors = {"Red", "Green", "Blue", "Yellow", "Purple"};
	static int stt = 1;

	private static void Backtracking(int i, int n) {
		
		for (int k = 0; k <= 1; ++k) {
			selections[i] = k;
			if (i == n) {
				process();
				stt++;
			} else {
				Backtracking(i + 1, n);
			}
		}
	}

	private static void process() {
		System.out.print(stt + ": ");
		for (int i = 0; i < selections.length; ++i) {
			if (selections[i] != 0) {
				System.out.print(colors[i] + " ");
			}
		}
		System.out.println("");
	}
	public static void main(String[] args) {
		Backtracking(0, 4);
	}
}