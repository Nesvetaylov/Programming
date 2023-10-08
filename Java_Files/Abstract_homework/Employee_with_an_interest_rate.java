package Abstract_homework;

class Employee_with_an_interest_rate extends Worker {
    private double baseSalary;
    private double interestRate;

    public Employee_with_an_interest_rate(String name, double baseSalary, double interestRate) {
        super(name);
        this.baseSalary = baseSalary;
        this.interestRate = interestRate;
    }

    public void assignSalary() {
        this.salary = baseSalary + (baseSalary * interestRate);
    }
}