package Abstract_homework;

public class Main_Worker {
    public static void main(String[] args) {
        Employee_with_hourly_pay employee1 = new Employee_with_hourly_pay("John", 10.0);
        employee1.assignSalary();
        employee1.displayInfo();

        Employee_in_the_state employee2 = new Employee_in_the_state("Alice", 1000.0);
        employee2.assignSalary();
        employee2.displayInfo();

        Employee_with_an_interest_rate employee3 = new Employee_with_an_interest_rate("Bob", 2000.0, 0.05);
        employee3.assignSalary();
        employee3.displayInfo();
    }
}