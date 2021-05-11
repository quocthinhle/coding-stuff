import java.util.EmptyStackException;

public class stack {

    private static class StackNode<T> {
        private T data;
        private StackNode<T> next;

        public StackNode (T data) {
            this.data = data;
        }

        private StackNode<T> top;

        public T pop() {
            if (top == null) throw new EmptyStackException();
            T item = top.data;
            top = top.next;
            return item;
        }

        public void push(T item) {
            StackNode<T> t = new StackNode<>(item);
            t.next = top;
            top = t;
        }

        public boolean isEmpty() {
            return top == null;
        }

        public T peek() {
            if (top == null) throw new EmptyStackException();
            return top.data;
        }

    }
    public static void main(String[] args) {
        StackNode<Integer> t = new StackNode<>(5);
        t.push(3);
        t.push(5);
        System.out.println(t.pop());
    }
}