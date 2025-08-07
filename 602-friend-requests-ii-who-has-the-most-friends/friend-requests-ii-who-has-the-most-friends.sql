WITH
    combine_cols AS (
        SELECT
            requester_id AS id
        FROM RequestAccepted

        UNION ALL

        SELECT
            accepter_id AS id
        FROM RequestAccepted
    ),

    num_friends AS (
        SELECT
            id,
            COUNT(id) AS num
        FROM combine_cols
        GROUP BY id
    )

SELECT 
    * 
FROM 
    num_friends
WHERE
    num = (SELECT MAX(num) FROM num_friends)
;