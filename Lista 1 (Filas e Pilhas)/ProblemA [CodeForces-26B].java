import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String bracket = in.nextLine();
		Stack stack = new Stack();
		int aux = 0;
		int aux2 = 0;
		
		for (int i = 0; i < bracket.length(); i++) {
			if (bracket.charAt(i) == '(') {
				stack.push('(');
				aux2++;
			}
			else {
				if (stack.top == null){
					aux++;
				}
				else {
					stack.pop();
					aux2--;
				}
			}
		}
		System.out.println(bracket.length() - (aux + aux2));
	}
}
class Node {
	char data;
	Node next;

	public Node(char data) {
		this.data = data;
		this.next = null;
	}
}

class Stack {
	Node top;

	public Stack() {
		this.top = null;
	}

	public void push(char data) {
		Node aux = new Node(data);
		if (this.top == null)// pilha vazia
			this.top = aux;
		else {
			aux.next = this.top;
			this.top = aux;
		}
	}

	public void pop() {
		if (this.top == null)
			return;
		else {
			this.top = this.top.next;
		}
	}

}