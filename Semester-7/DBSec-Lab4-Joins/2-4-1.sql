SELECT "Masters"."SecondName"
FROM "Masters"
WHERE "Masters"."MasterID" IN (
	SELECT "Orders"."MasterID"
	FROM "Orders"
	WHERE "Orders"."CarID" IN (
		SELECT "Cars"."CarID"
		FROM "Cars"
		WHERE "Cars"."Brand" = 'Волга'
	)
)