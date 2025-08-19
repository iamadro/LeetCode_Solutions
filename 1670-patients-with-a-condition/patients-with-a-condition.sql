SELECT
    patient_id,
    patient_name,
    conditions
FROM Patients
WHERE
    LEFT(conditions, 5) = "DIAB1"
    OR
    INSTR(conditions, " DIAB1") > 0
;