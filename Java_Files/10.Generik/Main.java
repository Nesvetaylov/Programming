package Generik;



public class Main {
    public static void main(String[] args) {
        // Создаем новый список типа Integer
        List<Integer> list = new List<>();

        // Добавляем элементы в список
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        System.out.println("Введенный список: ");
        list.print();

        // Удаляем элемент с индексом 1
        list.remove(1);


        // Выводим список после удаления элемента
        System.out.println("Список после удаления элемента: ");
        list.print();

        // Удаляем элемент с индексом 2
        list.remove(2);


        // Выводим список после удаления элемента
        System.out.println("Список после удаления элемента: ");
        list.print();

        // Удаляем элемент с индексом 2
        list.remove(3);

        // Выводим список после удаления элемента
        System.out.println("Список после удаления элемента: ");
        list.print();

    }
}
