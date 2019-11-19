# Write your MySQL query statement below

select Score,(select count(distinct Score) from Scores where score >= s.score) as Rank from Scores s order by Score DESC
