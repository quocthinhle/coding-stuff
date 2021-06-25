import java.util.EmptyStackException;

public class Stack {
	private static class StackNode<T> {
		private StackNode<T> next;
		private T value;
		private StackNode<T> top;

		public StackNode(T data) {
			this.value = data;
		}

		public void push(T data) {
			StackNode<T> newTop = new StackNode<T>(data);
			newTop.next = this.top;
			this.top = newTop;
		}

		public T pop() {
			if (this.top == null) {
				throw new EmptyStackException();
			}
			T item = top.value;
			top = top.next;
			return item;
		}

		public boolean isEmpty() {
			return this.top == null;
		}

		public T peek() {
			if (top == null) throw new EmptyStackException();
			return top.value;
		}

	}

	public static void main(String[] args) {
		StackNode<String> stack = new StackNode<>("Hello");
		stack.push("Hi");
		stack.push("Hello");
		System.out.println(stack.peek());
	}
}