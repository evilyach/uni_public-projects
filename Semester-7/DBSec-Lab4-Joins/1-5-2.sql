SELECT "Masters"."SecondName",
       COUNT("Orders"."MasterID") AS "Jobs done by"
FROM "Masters", "Orders"
WHERE "Orders"."MasterID" = "Masters"."MasterID"
GROUP BY "Masters"."SecondName"