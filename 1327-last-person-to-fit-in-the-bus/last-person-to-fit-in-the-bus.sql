SELECT 
    q2.person_name
FROM
    Queue q2
JOIN (
    SELECT
        person_id,
        (
            SUM(weight) OVER(ORDER BY turn) 
        ) cumm_weight
    FROM
        Queue
) q
ON q.person_id = q2.person_id
WHERE cumm_weight <= 1000
ORDER BY cumm_weight DESC
LIMIT 1
;