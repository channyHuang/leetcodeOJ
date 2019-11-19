# Write your MySQL query statement below

select distinct l1.Num ConsecutiveNums from Logs l1 join Logs l2 on l1.Id = l2.Id - 1 join Logs l3 on l1.Num = l3.Num and l1.Id = l3.Id - 2 where l1.num = l2.num and l2.num = l3.num
