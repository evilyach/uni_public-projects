SELECT "Masters"."SecondName",
       "Cars"."Brand",
       "Orders"."Date",
       "Orders"."Price" AS "Price (RUB)",
       ROUND("Orders"."Price" / 60, 2) AS "Price (USD)",
       ROUND("Orders"."Price" / 70, 2) AS "Price (EUR)"
FROM "Masters", "Cars", "Orders"
WHERE "Orders"."MasterID" = "Masters"."MasterID" AND
      "Orders"."CarID" = "Cars"."CarID"