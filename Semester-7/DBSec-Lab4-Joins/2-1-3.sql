SELECT "Masters"."SecondName"
FROM "Masters", "Orders"
WHERE "Orders"."Price" = (
	SELECT MAX("Orders"."Price")
	FROM "Orders", "Masters"
	WHERE "Masters"."SecondName" IS NOT NULL
) AND
      "Orders"."MasterID" = "Masters"."MasterID"