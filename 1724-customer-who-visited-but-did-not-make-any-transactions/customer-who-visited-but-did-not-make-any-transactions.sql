# Write your MySQL query statement below
SELECT Visits.customer_id, COUNT(customer_id) as count_no_trans
FROM Visits
WHERE Visit_id not in (SELECT Visit_id FROM transactions)
group by customer_id 
