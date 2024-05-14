--(1)�� ������� ������������, �������������� � ��� �� ������, ��� � �����������,
--������������� �������� �������� King, ������� ��������� ���������� � �������� � ���������������� �������:
--department_name, first_name, last_name. 
SELECT dep.department_name, emp.first_name, emp.last_name
FROM departments dep 
JOIN employees emp ON dep.manager_id = emp.employee_id
WHERE dep.location_id IN (
    SELECT location_id 
    FROM departments 
    WHERE manager_id IN (
        SELECT employee_id 
        FROM employees
        WHERE first_name = 'King' )
);

--(2)������� �������� �������������, ������� ������������� � ���.
SELECT dep.department_name
FROM departments dep
WHERE dep.location_id IN (
    SELECT location_id
    FROM locations loc
    WHERE loc.country_id='US'
);
    
--(3)������� �������� �������������, ��������������� � ���, � ������� �� �������������,
--� ������� �������� ���� �� ���� ����������� (job_title = programmer).
SELECT dep.department_name, emp.last_name
FROM departments dep
JOIN employees emp ON dep.manager_id = emp.employee_id
WHERE dep.location_id IN (
    SELECT loc.location_id 
    FROM locations loc
    WHERE loc.country_id = (
        SELECT c.country_id
        FROM countries c 
        WHERE c.country_name = 'USA'
    )
)
AND EXISTS (
    SELECT 1 
    FROM employees e 
    WHERE e.department_id = dep.department_id 
    AND e.job_id = 'programmer'
);

--7) �� ������� ������ �������:
-- �������� ������
-- ���������� �������������
-- ��������� ������� �� ������ ��������
-- ���������� �����������
SELECT 
  loc.city, 
  COUNT(dep.department_id) AS number_of_departments, 
  SUM(emp.salary) AS total_salary_expenses, 
  COUNT(emp.employee_id) AS number_of_employees
FROM 
  departments dep 
  JOIN employees emp ON dep.department_id = emp.department_id 
  JOIN locations loc ON dep.location_id = loc.location_id 
WHERE 
  dep.department_id IN (SELECT department_id FROM employees WHERE job_id = 'IT_PROG') 
GROUP BY 
  loc.city;


select * from employees;
