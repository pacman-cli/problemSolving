
public class Node {
    int data;
    Node next;

    Node(int data1, Node nextNode) {
        this.data = data1;
        this.next = nextNode;
    }

    Node(int data1) {
        this.data = data1;
        this.next = null;
    }

}

class deleteANode {
    public static Node deleteTail(Node head) {
        if (head == null || head.next == null) {
            return null;
        }
        Node temp = head;
        // Traverse the list until the second-to-last node
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
        return head;

    }

    public static void printNodes(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }

    public static void main(String[] args) {
        int[] arr = { 2, 5, 8, 7 };
        Node head = new Node(arr[0]);
        head.next = new Node(arr[1]);
        head.next.next = new Node(arr[2]);
        head.next.next.next = new Node(arr[3]);

        head = deleteTail(head);

        printNodes(head);

    }
}