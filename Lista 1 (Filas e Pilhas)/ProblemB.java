import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int aux = 0;

		while (in.hasNext()) {
		    Queue queue = new Queue();
			int nCards = in.nextInt();
			
			if (nCards != 0) {
			    for (int i = 1; i <= nCards; i++) {
				    queue.enqueue(i);
				    aux++;
			    }
			    System.out.print("Discarded cards:");
			    while (aux > 1) {
				    System.out.print(" " + queue.top.card);
				    queue.deQueue();
				    queue.enqueue(queue.top.card);
				    queue.deQueue();
				    aux--;
				    if (aux > 1) {
					System.out.print(",");
				    }
			    }
			    System.out.print("\nRemaining card: "+ queue.top.card + "\n");
			}
			aux = 0;
		}
	}
}
class Node{
	int card;
	Node next;
	
	public Node(int card) {
		this.card = card;
		this.next = null;
		
	}
}
class Queue{
	
	Node top;
	Node rear;
	
	public Queue() {
		this.top = null;
		this.rear = null;
	}
	
	public void deQueue() {
		//retira do inicio da fila (top)
		this.top = this.top.next;
		if(this.top == null)
			this.rear = null;	
	}
	
	public void enqueue(int card) {
		//coloca no fim da fila (rear)
		Node aux = new Node(card);
		if(this.top == null) {
			this.top = this.rear = aux;
		}else {
			this.rear.next = aux;
			this.rear = aux;
		}
	}
}