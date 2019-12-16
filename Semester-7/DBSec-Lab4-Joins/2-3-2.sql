SELECT DISTINCT *
FROM "Masters" AS "Master"
WHERE NOT EXISTS (
	SELECT DISTINCT *
	FROM "Orders", "Cars", "Masters"
	WHERE "Orders"."CarID" = "Cars"."CarID" AND
	      "Orders"."MasterID" = "Masters"."MasterID"
)