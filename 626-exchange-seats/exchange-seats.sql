SELECT
    t1.id,
    IFNULL(t2.student, t1.student) as student
FROM
    Seat t1
LEFT JOIN
    Seat t2
ON
    CASE
        WHEN t1.id % 2 = 1 THEN t1.id + 1 = t2.id
        ELSE t1.id - 1 = t2.id
    END
;