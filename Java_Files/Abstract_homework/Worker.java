package Abstract_homework;

abstract class Worker {
    protected String name;
    protected double salary;

    public Worker(String name) {
        this.name = name;
        this.salary = 0.0;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public double getSalary() {
        return this.salary;
    }

    public abstract void assignSalary(); // абстрактный метод, который будет переопределен в производных классах

    public void displayInfo() {
        System.out.println("Name: " + this.name);
        System.out.println("Salary: " + this.salary);
    }
}
