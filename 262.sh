# Write your MySQL query statement below

select t.Request_at Day, (round(count(if(status != 'completed', Status, null)) / count(Status), 2)) as 'Cancellation Rate' from Trips t left join Users u1 on u1.Users_id = t.Client_Id left join Users u2 on u2.Users_id = t.Driver_Id where u1.Banned = 'No' and u2.Banned = 'No' and t.Request_at >= '2013-10-01' and t.Request_at <= '2013-10-03' group by t.Request_at
