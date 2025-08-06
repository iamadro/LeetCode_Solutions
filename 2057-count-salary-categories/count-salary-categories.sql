WITH 
    classified AS (
    SELECT 
        account_id,
        income,
        (
            CASE WHEN income < 20000 THEN "Low Salary"
            ELSE (
                CASE WHEN income <= 50000 THEN "Average Salary"
                ELSE "High Salary"
                END
            ) 
            END
        ) AS category
        FROM
        Accounts
    ),

    all_categories AS (
        SELECT 'Low Salary' AS category
        UNION ALL SELECT 'Average Salary' as category
        UNION ALL SELECT 'High Salary' as category
    ),
    
    counted AS (
        SELECT 
            category,
            count(*) as accounts_count
        FROM classified
        GROUP BY category
    )

SELECT all_categories.category, coalesce(counted.accounts_count, 0) AS accounts_count
FROM all_categories
LEFT JOIN counted
USING(category)
;