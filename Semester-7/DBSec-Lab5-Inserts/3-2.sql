DELETE
FROM "Kardanov_Orders"
WHERE "Kardanov_Orders"."CarID" IN (
	SELECT "Cars"."CarID"
	FROM "Cars"
	WHERE "Cars"."Brand" = 'Лада'
)