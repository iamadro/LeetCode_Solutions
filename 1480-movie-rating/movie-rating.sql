WITH 
    user_ratings AS (
        SELECT 
            user_id,
            count(*) AS num_ratings
        FROM
            MovieRating
        GROUP BY user_id
    ),

    highest_rater AS (
        SELECT 
            u.name
        FROM Users u
        JOIN user_ratings ur
        USING (user_id)
        ORDER BY ur.num_ratings DESC, u.name ASC
        LIMIT 1
    ),

    movie_avg_rating AS (
        SELECT 
            movie_id,
            AVG(rating) avg_rating
        FROM
            MovieRating
        WHERE 
            created_at BETWEEN '2020-02-01' AND '2020-02-29'
        GROUP BY
            movie_id
    ),

    highest_movie AS (
        SELECT 
            m.title
        FROM
            movie_avg_rating ma
        JOIN
            Movies m
        USING(movie_id)
        ORDER BY
            ma.avg_rating DESC,
            m.title ASC
        LIMIT 1
    )

SELECT name as 'results' FROM highest_rater
UNION ALL SELECT title FROM highest_movie
;