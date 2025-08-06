SELECT 
    e.employee_id
FROM Employees e
LEFT JOIN Employees m
ON m.employee_id = e.manager_id
WHERE e.manager_id IS NOT NULL AND m.employee_id IS NULL AND e.salary < 30000
ORDER BY e.employee_id
;

-- SELECT 
--     e.employee_id
-- FROM Employees e
-- WHERE 
--     e.manager_id IS NOT NULL
--     AND
--     NOT EXISTS (
--         SELECT m.employee_id 
--         FROM Employees m
--         WHERE m.employee_id = e.manager_id
--     )
--     AND 
--     e.salary < 30000
-- ORDER BY 
--     e.employee_id
-- ;
