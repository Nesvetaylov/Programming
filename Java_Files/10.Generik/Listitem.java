package Generik;

public class Listitem <item> {
    private item data;
    private Listitem<item>next;
    private Listitem<item>prev;
    Listitem(item d) {
        data=d;
        next=null;
        prev=null;
    }

    public item getData() {
        return data;
    }
    public void setData(item d) {
        data = d;
    }
    public Listitem<item>getPrev() {
        return prev;
    }
    public Listitem<item>getNext() {
        return next;
    }

    public void setPrev(Listitem<item> li) {
        prev=li;
    }

    public void setNext(Listitem<item> li) {
        next=li;
    }
}
