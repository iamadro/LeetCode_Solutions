WITH 
    locations AS (
        SELECT
            lat,
            lon,
            count(*) AS same_locations
        FROM Insurance
        GROUP BY lat, lon
    ),
    invests_2015 AS (
        SELECT
            tiv_2015,
            count(*) AS same_investments
        FROM Insurance
        GROUP BY tiv_2015
    )

SELECT 
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance
JOIN 
    invests_2015 ON invests_2015.tiv_2015 = Insurance.tiv_2015
JOIN
    locations ON locations.lat = Insurance.lat AND locations.lon = Insurance.lon
WHERE
    same_locations = 1
    AND
    same_investments > 1
;