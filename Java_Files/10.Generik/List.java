package Generik;

public class List <item>{
    private int kol;
    private Listitem<item>first;
    private Listitem<item>last;
    List() {
        kol=0;
        first=null;
        last=null;
    }
    List(item data) {
        first=last=new Listitem<item>(data);
        kol=1;
    }
    public void add(item data) {
        Listitem<item>li=new Listitem<item>(data);
        li.setNext(null);
        if (kol>0) {
            li.setPrev(last);
            last.setNext(li);
        }
        else {
            first=li;
        }
        last=li;
        kol++;
    }

    public Listitem<item> getFirst() {
        return first;
    }

    public Listitem<item> getLast() {
        return last;
    }

    public int getquan() {
        return kol;
    }
    public Listitem<item>get(int i) {
        if (i>kol) {
            return null;
        }
        else {
            Listitem<item>li=first;
            for (int j=1;j<i;j++) {
                li=li.getNext();
            }
            return li;
        }
    }
    void print() {
        Listitem<item>li=first;
        while(li!=null) {
            System.out.println(li.getData());
            li=li.getNext();
        }
    }

    public void remove(int i) {
        if (i<=kol) {
            Listitem<item>li=get(i);
            Listitem<item>prev=li.getPrev();
            Listitem<item>next=li.getNext();
            if (prev!=null) {
                prev.setNext(next);
            }
            if (next!=null) {
                next.setPrev(prev);
                if (i==1) {
                    first=next;
                }
            }
            kol--;
        }
    }
}
