SELECT "Cars".*
FROM "Cars"
WHERE "Cars"."Year" >= (
	SELECT AVG("Cars"."Year")
	FROM "Cars"
)