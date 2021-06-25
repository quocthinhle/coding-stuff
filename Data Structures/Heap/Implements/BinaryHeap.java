import java.util.Arrays;

public class BinaryHeap {
	// Static class is used when it's a nested class, we can use it without create a instance of its outer class
	private static class MaxHeap {
		private int[] heap;
		private int size;
		private int maxSize;

		private static final int MAX_ARRAY_SIZE = Integer.MAX_VALUE - 8;

		public MaxHeap(int maxSize) {
			this.maxSize = maxSize;
			heap = new int[maxSize + 1];
			heap[0] = Integer.MAX_VALUE;
			this.size = 0;
		}

		private int Parent(int pos) {
			return pos/ 2;
		}

		private int LeftChild(int pos) {
			return 2*pos;
		}

		private int RightChild(int pos) {
			return 2*pos + 1;
		}

		private boolean IsLeaf(int pos) {
			if (pos >= size/2 && pos <= size) return false;
			return true;
		}

		private int swap(int a, int b) {
			return a;
		}

		private void SiftUp(int i) {
			while (i > 1 && heap[Parent(i)] < heap[i]) {
				heap[i] = swap(heap[Parent(i)], heap[Parent(i)] = heap[i]);
				i = Parent(i);
			}
		}

		private void grow(int previousSize) {
			this.maxSize = previousSize * 2 + 1;
			this.heap = Arrays.copyOf(heap, this.maxSize);
		}

		private void SiftDown(int i) {
			int maxIndex = i;
			int LeftChild = LeftChild(i);
			int RightChild = RightChild(i);

			if (LeftChild <= size && heap[LeftChild] > heap[maxIndex]) {
				maxIndex = LeftChild;
			}

			if (RightChild <= size && heap[RightChild] > heap[maxIndex]) {
				maxIndex = RightChild;
			}

			if (maxIndex != i) {
				heap[i] = swap(heap[maxIndex], heap[maxIndex] = heap[i]);
				SiftDown(maxIndex);
			}
		}


		private void Insert(int val) {
			if (this.size == this.maxSize) {
				grow(this.size);
			}
			this.size += 1;
			heap[this.size] = val;
			SiftUp(this.size);
		}

		private int ExtractMax() {
			if (this.size == 0) throw new Error("Out of bound")

			int val = heap[1];
			heap[1] = heap[size];
			size -= 1;
			SiftDown(1);
			return val;
		}

		private void Display() {
			for (int i = 1; i <= size; ++i) {
				System.out.print(heap[i] + " ");
			}
			System.out.println("");
		}

		public int getCurrentSize() {
			return this.size;
		}

	}


	public static void main(String[] args) {
		int arr[] = {5,4,1,2,8};
		int size = 5;
		MaxHeap mh = new MaxHeap(10);
		for (int i = 0; i < size; ++i) {
			mh.Insert(arr[i]);
		}
		mh.Insert(10);
		mh.Insert(-1);
		mh.Display();
		
		System.out.println(mh.ExtractMax());
		System.out.println(mh.ExtractMax());
		System.out.println(mh.ExtractMax());
		System.out.println(mh.ExtractMax());
		System.out.println(mh.ExtractMax());
		System.out.println(mh.ExtractMax());
		System.out.println(mh.ExtractMax());
		System.out.println(mh.ExtractMax());
	}
}