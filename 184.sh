# Write your MySQL query statement below

select Department.Name as Department, Employee.Name as Employee, Employee.Salary from Department inner join Employee on Employee.DepartmentId = Department.Id and Employee.Salary >= (select max(Salary) from Employee where DepartmentId = Department.Id)
