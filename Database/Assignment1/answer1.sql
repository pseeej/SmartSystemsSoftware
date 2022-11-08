-- 3. Employees와 Departments 테이블에 저장된 튜플의 개수를 출력하시오
select count(*) from employees -- 107
select count(*) from departments -- 27

-- 4. Employees 테이블에 대한 employee_id, last_name, job_id, hire_date를 출력하시오
select employee_id, last_name, job_id, hire_date
from employees

-- 5. employees 테이블에서 salary가 12000 이상인 직원의 last_name과 salary를 출력하시오
select last_name, salary
from employees
where salary >= 12000

-- 6. 부서번호(department_id)가 20 혹은 50인 직원의 last_name과 department_id를 last_name에 대하여 오름차순으로 출력하시오
select last_name, department_id
from employees
where department_id = 20 or department_id = 50
order by last_name asc

-- 7. last_name의 세 번째에 a가 들어가는 직원의 last_name을 출력하시오.
select last_name
from employees
where last_name like "__a%"

-- 8. 같은 일(job)을 하는 사람의 수를 세어 출력하시오.
select job_id, count(*)
from employees
group by job_id

-- 9. 급여(salary)의 최댓값과 최솟값의 차이를 구하시오
select max(salary) - min(salary)
from employees

-- 10. Toronto에서 일하는 직원의 last_name, job, department_id, department_name을 출력하시오
select last_name, job_title, department_id, department_name
from emp_details_view
where city = "Toronto"

-- 11. last_name이 Matos, Taylor인 직원들의 last_name, job_id, start_date를 출력하고 start_date를 기준으로 오름차순 정렬
select employees.last_name, job_history.job_id, job_history.start_date
from job_history, employees
where employees.last_name = "Matos" or employees.last_name = "Taylor"
order by job_history.start_date asc

-- 12. 1994년에 hire된 모든 직원들의 last_name과 hire_date을 출력하라
select last_name, hire_date
from employees
where hire_date between "1994-01-01" and "1994-12-31"

-- 13. 직업이 sales representative이거나 stock clerk이면서 salary가 2500, 3500, 7000이 아닌 직원들의 last name, job, salary를--  보여라.
select employees.last_name, jobs.job_title, employees.salary
from employees, jobs
where jobs.job_id in (select job_id from jobs where job_title = "Sales Representative" or job_title = "Stock Clerk")
		and employees.salary != 2500 and employees.salary != 3500 and employees.salary != 7000

-- 14. manager의 수를 count하고 이 결과를 number of mangers라는 이름으로 labelling해라
select count(m.manager_id) as "Number of Managers"
from (select manager_id, count(*) from emp_details_view group by manager_id) as m

-- 15. 매니저 번호와 그 매니저 아래에서 salary가 가장 적은 employee의 salary를 보여라.
--     매니저가 unknown이거나 그 그룹의 minimum salary가 6000이하일 경우 제외
--     salary를 기준으로 내림차순 정렬하여라.
select manager_id, min(salary)
from employees
where manager_id is not null and salary > 6000
group by manager_id
order by min(salary) desc

-- 16. 매니저의 last name과 manager number와 함께 employee의 num과 last name을 보여라
--     column 이름을 Employee, Emp#, Manager, Mgr#로 두기
select e.last_name as "Employee", e.employee_id as "Emp#", m.last_name as "Manager", m.employee_id as "Mgr#"
from employees as e join employees m
on e.manager_id = m.employee_id

-- 17. employee의 last name, department numbers, 그리고 주어진 employee와 같은 department에 일하는 모든 employee를 보여라
select e.last_name, e.department_id, c.last_name
from employees e join employees c
on e.department_id = c.department_id
where e.employee_id <> c.employee_id

-- 18. Executive department에서 근무하는 모든 직원에 대한 department number, last name, job id를 보여라
select e.department_id, e.last_name, e.job_id
from employees e
where e.department_id = (select department_id from departments where department_name like "Executive")

-- 19. manager의 이름이 King인 직원들의 last name과 salary를 보여라
select e.last_name, e.salary
from employees e join employees c
on e.manager_id = c.employee_id
where c.last_name like "King"

-- 20. job id ST_CLERK를 포함하지 않는 department id의 리스트를 보여라
select department_id
from departments
where department_id not in (select department_id
							from employees
							where job_id = "ST_CLERK")
