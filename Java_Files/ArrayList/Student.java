import java.util.ArrayList;

public class Student {
    private String fio;
    private String address;
    private String faculty;
    private int course;
    private ArrayList<Integer> grades;

    public Student(String fio, String address, String faculty, int course, ArrayList<Integer> grades) {
        this.fio = fio;
        this.address = address;
        this.faculty = faculty;
        this.course = course;
        this.grades = grades;
    }

    public String getFio() {
        return fio;
    }

    public void setFio(String fio) {
        this.fio = fio;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getFaculty() {
        return faculty;
    }

    public void setFaculty(String faculty) {
        this.faculty = faculty;
    }

    public int getCourse() {
        return course;
    }

    public void setCourse(int course) {
        this.course = course;
    }

    public ArrayList<Integer> getGrades() {
        return grades;
    }

    public void setGrades(ArrayList<Integer> grades) {
        this.grades = grades;
    }

    public void displayInfo() {
        System.out.println("ФИО: " + fio);
        System.out.println("Адрес: " + address);
        System.out.println("Факультет: " + faculty);
        System.out.println("Курс: " + course);
        System.out.println("Оценки: " + grades);
    }

    public double calculateAverageGrade() {
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return (double) sum / grades.size();
    }
}
