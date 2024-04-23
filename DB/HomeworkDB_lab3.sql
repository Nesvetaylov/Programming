--������������ ������ �3
--(1)�������� ������ �� �������������: ��� ������� ������������ ���������� ����������� � ������������ ��������,
--���������� ���� ���������� �� ������ ������� � ���������� ����������, � ����� ����� ���������� ����������� � ������������. ����������� �� ���������� ����������� (�� ��������)
SELECT dep.department_name AS "�������� ������������",
MIN(emp.salary) AS "����������� ��������",
MAX(emp.salary) AS "������������ ��������",
MIN(emp.hire_date) AS "���� ���������� ������� ����������",
MAX(emp.hire_date) AS "���� ���������� ���������� ����������",
COUNT(emp.employee_id) AS "���������� �����������"
FROM HR.departments dep LEFT OUTER JOIN HR.employees emp ON dep.department_id=emp.department_id
GROUP BY dep.department_name ORDER BY COUNT(emp.employee_id) DESC;
--(2)��� ������� ���� ������� ���������� ����������� ������� � ���� ����.
--����������� �� ���������� �����������.
SELECT EXTRACT(YEAR FROM emp.hire_date) AS "���",
COUNT (emp.employee_id) AS "����������� �����������"
FROM HR.employees emp LEFT OUTER JOIN HR.departments dep ON emp.department_id=dep.department_id
GROUP BY EXTRACT(YEAR FROM emp.hire_date)
ORDER BY "����������� �����������" DESC;
--(3)����� ����������� (� ������ �� manager_id), � ������� ���������� ����������� ������ 5
--� ����� ���� ������� ����������� ������ 50000.
SELECT dep.manager_id AS "�����������", COUNT(emp.employee_id) AS "���������� ����������� > 5",
SUM(emp.salary) AS "����� ��������", dep.department_name AS "��� ������������"
FROM HR.departments dep LEFT OUTER JOIN HR.employees emp ON dep.department_id=emp.department_id
GROUP BY dep.manager_id, dep.department_name HAVING COUNT(emp.employee_id) >5 AND SUM(emp.salary) > 50000;
--(4)�������� ������������ �������� ����� ���� ������� ������� �� ������������.
SELECT MAX("������� ��������") AS "������������ ������� ��������"
FROM (SELECT AVG(emp.salary) AS "������� ��������"
    FROM HR.employees emp JOIN HR.departments dep ON emp.department_id=dep.department_id
    GROUP BY dep.department_name);








