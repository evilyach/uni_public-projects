SELECT "Masters".*
FROM "Masters"
WHERE "Masters"."WorkExperience" > (
	SELECT "Masters"."WorkExperience"
	FROM "Masters"
	WHERE "Masters"."SecondName" = 'Тормозякин'
)