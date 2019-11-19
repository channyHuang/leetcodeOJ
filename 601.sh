# Write your MySQL query statement below

select distinct s4.id,s4.visit_date,s4.people from stadium s1,stadium s2,stadium s3,stadium s4 where s1.id + 1 = s2.id and s2.id + 1 = s3.id and s1.people >= 100 and s2.people >= 100 and s3.people >= 100 and s4.id in (s1.id,s2.id,s3.id)
