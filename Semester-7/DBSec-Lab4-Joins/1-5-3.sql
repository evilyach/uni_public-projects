SELECT AVG("Orders"."Price") AS "Average price of Kolenvalov' job" 
FROM "Orders", "Masters"
WHERE "Orders"."MasterID" = "Masters"."MasterID" AND
      "Masters"."SecondName" = 'Коленвалов'