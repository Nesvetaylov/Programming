package LinkedList;

import java.util.*;

public class MyList {
    LinkedList<String> list;
    MyList()
    {
        list=new LinkedList<String>();
    }
    void createlist() {
        String s;
        Scanner sc=new Scanner(System.in);
        s=sc.nextLine();
        while(!s.equals("")) {
            list.addLast(s);// добавление элемента в конец
            s=sc.nextLine();
        }
    }
    void print() {
        ListIterator<String> it=list.listIterator();//Создали итератор на основе списка
        while(it.hasNext()) {
            System.out.println(it.next());
        }
    }
    void print_reverse() {
        ListIterator <String> it=list.listIterator(list.size());//ставим итератор в конец списка
        while(it.hasPrevious()) {
            System.out.println(it.previous());//идём в обратную сторону
        }
    }
    void del(String s) { //с помощью итератора удаляем элементы с заданными значениями
        ListIterator<String> it=list.listIterator();
        while(it.hasNext()) {
            if (it.next().equals(s)) {
                it.remove();
            }
        }
    }
}
