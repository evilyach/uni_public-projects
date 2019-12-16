SELECT "Masters"."SecondName"
FROM "Masters"
WHERE "Masters"."WorkExperience" > ALL (
	SELECT "Masters"."WorkExperience" - 1
	FROM "Masters"
	WHERE "Masters"."WorkExperience" IS NOT NULL
)