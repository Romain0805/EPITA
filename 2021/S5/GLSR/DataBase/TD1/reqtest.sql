SELECT  DISTINCT(shop.name),
    CASE WHEN purchase_time < '2017-01-31' THEN 'old'
         WHEN purchase_time BETWEEN '2017-02-01' AND '2018-01-01' THEN 'outdated'
         WHEN purchase_time > '2018-01-01' THEN 'current'
    END AS purchase_time
FROM "shop", "student_can_shop"
WHERE shop.id = student_can_shop.shop_id
ORDER BY purchase_time