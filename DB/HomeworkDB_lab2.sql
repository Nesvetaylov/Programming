--������� ������ � SELECT
--(1)
select * from HR.employees emp where emp.salary=2500;
--(2)
select * from HR.employees emp where emp.salary!=2500 and emp.salary>2000;
--(3)
select * from HR.employees emp where emp.salary between 2000 and 3000;
--(4)
select * from HR.employees emp where emp.manager_id is null;
--(5)
select * from HR.employees emp where emp.department_id in(20,40,50);
--(6)
select emp.department_id, count(emp.employee_id)
from HR.employees emp
group by emp.department_id;
--(7)
select emp.department_id,count(emp.employee_id)
from HR.employees emp
group by emp.department_id
having count(emp.employee_id)>5;
--(8)
select *
from HR.employees emp
order by emp.department_id desc;
--(9)
select *
from HR.employees emp
order by emp.last_name,emp.first_name asc;
--(10)
select emp.last_name, emp.department_id, dept.department_name
from HR.employees emp, HR.departments dept
where dept.department_id=emp.department_id;



------���������� ������������ �2 �� ��
--(1)
select emp.last_name, emp.commission_pct, dept.department_name, loc.city, loc.location_id
from HR.employees emp, HR.departments dept, HR.locations loc
where emp.department_id=dept.department_id and dept.location_id=loc.location_id
and emp.commission_pct is not null;
--(2)
select jb.job_title, loc.city, dept.department_id
from HR.jobs jb, HR.employees emp, HR.departments dept, HR.locations loc
where emp.department_id=dept.department_id and dept.location_id=loc.location_id
and emp.job_id=jb.job_id and dept.department_id=80;
--(3)
select emp.last_name, dept.department_name
from HR.employees emp, HR.departments dept
where emp.department_id=dept.department_id and lower(emp.last_name) like '%a%';
--(4)
select emp.last_name, jb.job_title,dept.department_id, dept.department_name, loc.city
from  HR.employees emp, HR.departments dept, HR.jobs jb, HR.locations loc
where emp.department_id=dept.department_id and emp.job_id=jb.job_id
and emp.department_id=dept.department_id and dept.location_id=loc.location_id
and loc.city='Toronto';
--(5)
select emp.last_name as Employee, emp.employee_id as "Emp#",
m.last_name as Manager,m.manager_id as "MGR#"
from HR.employees emp, HR.employees m
where emp.manager_id=m.employee_id;
--(6)
select emp.last_name as Employee, emp.employee_id as "Emp#",
m.last_name as Manager,m.manager_id as "MGR#"
from HR.employees emp, HR.employees m
where emp.manager_id=m.employee_id or (emp.manager_id is null and emp.employee_id=100)
order by emp.employee_id asc;
--(7)
select emp.department_id as "����� ������", emp.last_name as "������� ���������",
al.last_name as "������� ���� ��������"
from HR.employees emp, HR.employees al
where emp.department_id=al.department_id and emp.employee_id=106;
--(8)
select emp.last_name as "�������", jb.job_title as "���������",
dept.department_name as "�������� ������",emp.salary as "�����"
from HR.employees emp, HR.jobs jb, HR.departments dept
where emp.job_id=jb.job_id and emp.department_id=dept.department_id;
--(9)
select emp.last_name as "�������", emp.hire_date as "���� �����"
from HR.employees emp
where emp.last_name > 'Davies'
order by emp.last_name asc;
--���� ����� �������
select emp.last_name as "�������", emp.hire_date as "���� �����"
from HR.employees emp
where emp.last_name = 'Davies';
--����� ������������ ������ �����
alter session set nls_date_format='DD.MM.YYYY';
--(10)
select emp.last_name as "������� ����������", emp.hire_date as "���� ����� ����������",
m.last_name as "������� ���������", m.hire_date as "���� ����� ���������"
from HR.employees emp, HR.employees m
where m.employee_id=emp.manager_id and emp.hire_date < m.hire_date;
