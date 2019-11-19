# Write your MySQL query statement below

select d.Name Department, e.Name Employee, Salary from Employee e inner join Department d on e.DepartmentId = d.Id where (select count(distinct Salary) from Employee where Salary > e.Salary and DepartmentId = e.DepartmentId) < 3 order by e.DepartmentId, Salary DESC
