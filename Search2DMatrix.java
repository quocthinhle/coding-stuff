import java.lang.annotation.Target;

class Point {
	public int x;
	public int y;
	public Point(int x, int y) {
		this.x = x;
		this.y = x;
	}
}

public class Search2DMatrix {

	public static boolean Solve(int[][] matrix, int target, int xl, int yl, int xr, int yr) {
		if (xl == xr && yl == yr) return matrix[xl][yl] == target;

		if (xl >= matrix.length || yl >= matrix[0].length || target > matrix[xr][yr] || target < matrix[xl][yl]) return false;

		int midX = (xl + xr) >>> 1;
		int midY = (yl + yr) >>> 1;

		if (matrix[midX][midY] == target) return true;

		if (matrix[midX][midY] > target) {
			return  Solve(matrix, target, xl, yl, midX, midY) ||
				Solve(matrix, target, midX + 1, yl, xr, midY) ||
				Solve(matrix, target, xl, midY + 1, midX, yr);
		}
		else {
			return  Solve(matrix, target, midX + 1, yl, xr, midY) ||
				Solve(matrix, target, xl, midY + 1, midX, yr) ||
				Solve(matrix, target, midX + 1, midY + 1, xr, yr);
		}
	}

	public static boolean Solution(int[][] matrix, int target) {
		return Solve(matrix, target, 0, 0, matrix.length - 1, matrix[0].length - 1);
	}
	public static void main(String[] args) {
		int[][] matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
		int target = 5;
		if (Solution(matrix, target)) {
			System.out.println("Found");
		} else {
			System.out.println("Not found");
		}
	}
}