WITH 
    sum_per_day AS (
        SELECT
            visited_on,
            SUM(amount) amt_per_day
        FROM Customer
        GROUP BY visited_on
        ORDER BY visited_on
    ),

    running_avg AS (
        SELECT
            visited_on,
            SUM(amt_per_day) OVER (
                ORDER BY visited_on
                ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
            ) AS amount,
            ROUND (
                AVG(amt_per_day) OVER (
                    ORDER BY visited_on
                    ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
                ),
                2
            ) AS average_amount,
            ROW_NUMBER() OVER (
                ORDER BY visited_on
            ) AS rn
        FROM
            sum_per_day
    )
SELECT 
    visited_on,
    amount, 
    average_amount
FROM
    running_avg
WHERE
    rn >= 7
;