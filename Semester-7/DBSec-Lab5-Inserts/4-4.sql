UPDATE "Orders"
SET "Price" = "Price" * 1.2
WHERE "Orders"."MasterID" = (
	SELECT "Masters"."MasterID"
	FROM "Masters"
	WHERE "Masters"."WorkExperience" = (
		SELECT MAX("Masters"."WorkExperience")
		FROM "Masters"
	)
)