SELECT
    user_id,
    name,
    mail
FROM users
WHERE mail collate 'utf8mb3_bin' regexp '^[a-zA-Z][a-zA-Z0-9\\_\\.-]*@leetcode\\.com$'
;