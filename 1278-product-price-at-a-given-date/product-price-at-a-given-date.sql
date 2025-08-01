SELECT
    items.product_id,
    (CASE WHEN p2.dated IS NULL THEN 10 ELSE (
        SELECT new_price from products where product_id = items.product_id and change_date = p2.dated
    ) END) price
FROM (
    SELECT DISTINCT product_id from products
) items
LEFT JOIN (
    SELECT product_id, max(change_date) as dated
    FROM products
    where DATEDIFF('2019-08-16', change_date) >= 0
    GROUP BY product_id
) p2 ON items.product_id = p2.product_id
;