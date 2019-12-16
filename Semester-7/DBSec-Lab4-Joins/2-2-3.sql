SELECT "Cars".*
FROM "Cars"
WHERE "Cars"."Year" > ANY (
	SELECT "Cars"."Year"
	FROM "Cars"
	WHERE "Cars"."Year" IS NOT NULL
)