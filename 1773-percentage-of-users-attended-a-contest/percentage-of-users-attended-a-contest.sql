# Write your MySQL query statement below
select contest_id, 
ROUND(COUNT(r.user_id) * 100.0 / (SELECT COUNT(user_id) FROM Users), 2) AS percentage
from Users u
join Register r on r.user_id = u.user_id
group by contest_id
order by percentage desc , r.contest_id asc;