SELECT "Masters".*,
       "Orders"."Date"
FROM "Masters", "Orders"
WHERE "Orders"."MasterID" = "Masters"."MasterID"