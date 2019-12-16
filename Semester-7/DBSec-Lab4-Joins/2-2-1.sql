SELECT "Masters"."SecondName"
FROM "Masters"
WHERE "Masters"."SecondName" IN (
	SELECT "Masters"."SecondName"
	FROM "Masters", "Orders"
	WHERE "Masters"."MasterID" = "Orders"."OrderID"
	GROUP BY "Masters"."SecondName"
)
