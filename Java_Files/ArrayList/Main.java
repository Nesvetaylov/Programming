package ArrayList;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> grades = new ArrayList<>();
        grades.add(3);
        grades.add(4);
        grades.add(5);
        grades.add(5);

        Student student = new Student("Иванов Иван Иванович", "Москва, ул. Пушкина 10", "Информационные технологии", 3, grades);

        student.displayInfo();
        System.out.println("Средний балл: " + student.calculateAverageGrade());
    }
}