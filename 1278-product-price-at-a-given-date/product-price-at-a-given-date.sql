SELECT
    items.product_id,
    COALESCE(p.new_price, 10) AS price
FROM 
    (SELECT DISTINCT product_id FROM products) AS items
LEFT JOIN 
    (
        SELECT product_id, MAX(change_date) AS max_date
        FROM products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    ) AS last_change 
    ON items.product_id = last_change.product_id
LEFT JOIN 
    products AS p 
    ON last_change.product_id = p.product_id AND last_change.max_date = p.change_date;