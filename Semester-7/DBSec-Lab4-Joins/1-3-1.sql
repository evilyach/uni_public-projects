SELECT "Masters"."SecondName",
       "Cars"."Brand",
       "Orders"."Date",
       "Orders"."Price"
FROM "Masters", "Cars", "Orders"
WHERE "Orders"."MasterID" = "Masters"."MasterID" AND
      "Orders"."CarID" = "Orders"."CarID"