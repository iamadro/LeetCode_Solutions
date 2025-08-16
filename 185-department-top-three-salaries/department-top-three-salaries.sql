SELECT
    d.name AS Department,
    e.name AS Employee,
    e.Salary
FROM 
    (
        SELECT 
            departmentId,
            name,
            salary,
            DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) as salary_rank
        FROM Employee
    ) e
JOIN
    Department d ON e.departmentId = d.id
WHERE
    e.salary_rank <= 3
;