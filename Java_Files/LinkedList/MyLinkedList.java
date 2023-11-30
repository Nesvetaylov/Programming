package LinkedList;

public class MyLinkedList {
    public static void main(String[] args) {
        MyList i=new MyList();
        i.createlist();
        System.out.println("List: ");
        i.print();
        System.out.println();
        System.out.println("List reverse: ");
        i.print_reverse();
        i.del("111");
        System.out.println("List: ");
        i.print();
    }
}
