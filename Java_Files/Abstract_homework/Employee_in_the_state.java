package Abstract_homework;

class Employee_in_the_state extends Worker {
    private double baseSalary;

    public Employee_in_the_state(String name, double baseSalary) {
        super(name);
        this.baseSalary = baseSalary;
    }

    public void assignSalary() {
        this.salary = baseSalary * 1.1; // увеличиваем на 10%
    }
}