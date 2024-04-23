--Лабораторная работа №3
--(1)Получить данные по департаментам: для каждого департамента определить минимальную и максимальную зарплату,
--определить дату устройства на работу первого и последнего сотрудника, а также общее количество сотрудников в департаменте. Сортировать по количеству сотрудников (по убыванию)
SELECT dep.department_name AS "Название департамента",
MIN(emp.salary) AS "Минимальная зарплата",
MAX(emp.salary) AS "Максимальная зарплата",
MIN(emp.hire_date) AS "Дата устройства первого сотрудника",
MAX(emp.hire_date) AS "Дата устройства последнего сотрудника",
COUNT(emp.employee_id) AS "Количество сотрудников"
FROM HR.departments dep LEFT OUTER JOIN HR.employees emp ON dep.department_id=emp.department_id
GROUP BY dep.department_name ORDER BY COUNT(emp.employee_id) DESC;
--(2)Для каждого года вывести количество сотрудников нанятых в этом году.
--Сортировать по количеству сотрудников.
SELECT EXTRACT(YEAR FROM emp.hire_date) AS "Год",
COUNT (emp.employee_id) AS "Количествго сотрудников"
FROM HR.employees emp LEFT OUTER JOIN HR.departments dep ON emp.department_id=dep.department_id
GROUP BY EXTRACT(YEAR FROM emp.hire_date)
ORDER BY "Количествго сотрудников" DESC;
--(3)Найти управляющих (а именно их manager_id), у которых количество подчиненных больше 5
--и сумма всех зарплат подчиненных больше 50000.
SELECT dep.manager_id AS "Управляющий", COUNT(emp.employee_id) AS "Количество сотрудников > 5",
SUM(emp.salary) AS "Общая зарплата", dep.department_name AS "Имя департамента"
FROM HR.departments dep LEFT OUTER JOIN HR.employees emp ON dep.department_id=emp.department_id
GROUP BY dep.manager_id, dep.department_name HAVING COUNT(emp.employee_id) >5 AND SUM(emp.salary) > 50000;
--(4)Получить максимальную зарплату среди всех средних зарплат по департаменту.
SELECT MAX("Средняя зарплата") AS "Максимальная средняя зарплата"
FROM (SELECT AVG(emp.salary) AS "Средняя зарплата"
    FROM HR.employees emp JOIN HR.departments dep ON emp.department_id=dep.department_id
    GROUP BY dep.department_name);








