with    
    units_sold as (
        select 
            product_id,
            sum(unit) as unit
        from orders
        where order_date >= '2020-02-01' and order_date < '2020-03-01'
        group by product_id
    )
select p.product_name, u.unit 
from units_sold u
join products p
on p.product_id = u.product_id
where u.unit >= 100
;