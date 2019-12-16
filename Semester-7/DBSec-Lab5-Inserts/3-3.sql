DELETE
FROM "Payments"
WHERE "Payments"."StateSign" IN (
	SELECT "Cars"."StateSign"
	FROM "Cars"
	WHERE "Cars"."Brand" = 'Лада' OR
	      "Cars"."Brand" = 'Волга'
)