import java.util.Stack;

public class QueueUsingStacks<T> {
	private Stack<T> stack1; // For enqueuing
	private Stack<T> stack2; // For dequeuing

	public QueueUsingStacks() {
		stack1 = new Stack<>();
		stack2 = new Stack<>();
	}

	public void enqueue(T item) {
		// Simply push the item onto stack1
		stack1.push(item);
	}

	public T dequeue() {
		if (isEmpty()) {
			throw new IllegalStateException("Queue is empty.");
		}

		// If stack2 is empty, pop all items from stack1 and push onto stack2 to reverse
		// the order
		if (stack2.isEmpty()) {
			while (!stack1.isEmpty()) {
				stack2.push(stack1.pop());
			}
		}

		// Pop the item from stack2, which will be the first item added to the queue
		// (FIFO order)
		return stack2.pop();
	}

	public boolean isEmpty() {
		return stack1.isEmpty() && stack2.isEmpty();
	}

	public int size() {
		return stack1.size() + stack2.size();
	}

	public static void main(String[] args) {
		QueueUsingStacks<Integer> queue = new QueueUsingStacks<>();

		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);

		System.out.println("Dequeue: " + queue.dequeue()); // Dequeue: 1
		System.out.println("Dequeue: " + queue.dequeue()); // Dequeue: 2

		queue.enqueue(4);

		System.out.println("Dequeue: " + queue.dequeue()); // Dequeue: 3
		System.out.println("Dequeue: " + queue.dequeue()); // Dequeue: 4
	}
}
