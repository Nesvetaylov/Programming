package Abstract_homework;

class Employee_with_hourly_pay extends Worker {
    private double hourlyPay;

    public Employee_with_hourly_pay(String name, double hourlyPay) {
        super(name);
        this.hourlyPay = hourlyPay;
    }

    public void assignSalary() {
        this.salary = hourlyPay * 160; // предполагаем, что месяц равен 160 часам работы
    }
}
