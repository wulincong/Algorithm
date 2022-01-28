select * from employees
where hire_date =
(select max(hire_date) from employees)

select * from employees 
where hire_date = 
    (select hire_date from employees 
     order by hire_date 
     desc limit 2,1);

select last_name, first_name, dept_no 
    from dept_emp as d,  employees as e
    where d.emp_no = e.emp_no;

select last_name, first_name, dept_no 
    from employees as e left outer join dept_emp as d
    on e.emp_no = d.emp_no;

select dept_no, emp_no, maxSalary
from employees natural left join salaries 
    natural left join  (select dept_no, max(salary) as maxSalary
    from employees natural left join salaries
    GROUP by dept_no)
where salary=maxSalary;

select dept_no, emp_no, maxSalary
from dept_emp natural left join salaries 
    natural left join  (select dept_no, max(salary) as maxSalary
    from dept_emp natural left join salaries
    GROUP by dept_no) as M
where salary=M.maxSalary;

