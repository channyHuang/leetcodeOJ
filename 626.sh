# Write your MySQL query statement below

select s1.id, ifnull(s2.student, s1.student) student from seat s1 left join seat s2 on if(s1.id & 1, s1.id = s2.id - 1, s1.id = s2.id + 1) group by id
