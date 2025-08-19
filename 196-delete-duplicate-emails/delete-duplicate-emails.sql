DELETE e1
FROM Person e1, Person e2
WHERE e1.email = e2.email AND e1.id > e2.id
;